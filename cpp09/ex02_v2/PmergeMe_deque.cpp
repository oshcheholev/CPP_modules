// PmergeMe_deque.cpp
#include "PmergeMe.hpp"
#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

static int binaryFindInsertPosDeque(const std::deque<int>& cont, const int& value, int limit, int &comparisons, bool debug, int depth /*= 0*/, const std::string& tag /*= ""*/) {
    // bounded lower_bound over range [0, limit)
    if (limit <= 0) return 0;
    int left = 0;
    int right = limit - 1;
    while (left <= right) {
        int mid = left + (right - left + 1) / 2; // upper-mid
        comparisons++;
        if (debug) {
            std::cout << std::string(depth * 2, ' ') << "Comparison " << comparisons
                      << " (" << tag << "): mid[" << mid << "]=" << cont[mid]
                      << " < value=" << value << " -> ";
            std::cout << std::endl;
        }
        if (cont[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

static void sortDequeRecursive(std::deque<int>& arr, int& comparisons, bool debug, int depth = 0) {
    int size = arr.size();
    if (size <= 1) return;

    if (debug) {
        std::cout << std::string(depth * 2, ' ') << "[Size: " << size << "]" << std::endl;
    }

    // base cases
    if (size <= 3) {
        if (size == 1) return;

        if (size == 2) {
            comparisons++;
            if (debug) {
                std::cout << std::string(depth * 2, ' ') << "Comparison " << comparisons
                          << " (base): arr[0]=" << arr[0] << " vs arr[1]=" << arr[1] << std::endl;
            }
            if (arr[0] > arr[1]) std::swap(arr[0], arr[1]);
            return;
        }

        // size == 3:
        comparisons++;
        if (debug) {
            std::cout << "Comparison " << comparisons
                      << " (base): arr[0]=" << arr[0] << " vs arr[1]=" << arr[1] << std::endl;
        }
        if (arr[0] > arr[1]) std::swap(arr[0], arr[1]);

        comparisons++;
        if (debug) {
            std::cout << "Comparison " << comparisons
                      << " (base): arr[0]=" << arr[0] << " vs arr[2]=" << arr[2] << std::endl;
        }
        if (arr[0] > arr[2]) std::swap(arr[0], arr[2]);

        // Compare 1 and 2
        comparisons++;
        if (debug) {
            std::cout << "Comparison " << comparisons
                      << " (base): arr[1]=" << arr[1] << " vs arr[2]=" << arr[2] << std::endl;
        }
        if (arr[1] > arr[2]) std::swap(arr[1], arr[2]);

        return;
    }

    // Шаг 1: Создание пар
    std::deque<std::pair<int, int> > pairs; // (больший, меньший)
    std::deque<int> winners;

    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        comparisons++;
        if (debug) {
            std::cout << std::string(depth * 2, ' ') << "Comparison " << comparisons
                      << " (pair): arr[" << i << "]=" << arr[i] << " vs arr[" << (i+1) << "]=" << arr[i+1]
                      << std::endl;
        }
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
            winners.push_back(arr[i]);
        } else {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
            winners.push_back(arr[i + 1]);
        }
    }

    bool hasLeftover = (size % 2 == 1);
    int leftover = hasLeftover ? arr.back() : -1;

    if (debug) {
        std::cout << std::string(depth * 2, ' ') << "Pairs: " << pairs.size()
                  << ", leftover: " << (hasLeftover ? "yes" : "no") << std::endl;
    }

    // Шаг 2: Рекурсивная сортировка победителей
    sortDequeRecursive(winners, comparisons, debug, depth + 1);

    // Шаг 3: Восстановление проигравших в правильном порядке
    std::deque<int> losers(winners.size());
    for (size_t i = 0; i < winners.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].first == winners[i]) {
                losers[i] = pairs[j].second;
                pairs[j].first = -1; // Помечаем как использованную
                break;
            }
        }
    }

    // Шаг 4: Построение основной цепочки
    std::deque<int> mainChain;

    // Инициализируем основную цепочку всеми отсортированными победителями
    if (!winners.empty()) {
        mainChain = winners; // start chain with all winners in sorted order
    }

    // Шаг 5: Вставка проигравших в порядке Якобсталя
    if (winners.size() > 1) {
        // Генерируем последовательность Якобсталя (skeleton) (deque-версия)
        std::deque<int> jacob = PmergeMe::generateJacobsthalDeque(winners.size() - 1);

        // Построим полную Knuth/Ford–Johnson последовательность вставки проигравших
        std::vector<int> insertOrder;
        if (!jacob.empty()) {
            insertOrder.push_back(1);
            int prev = 1;
            for (size_t ji = 1; ji < jacob.size(); ++ji) {
                int j = jacob[ji];
                if (j > (int)winners.size()) break;
                insertOrder.push_back(j);
                for (int k = j - 1; k > prev && (int)insertOrder.size() < (int)winners.size(); --k) {
                    insertOrder.push_back(k);
                }
                prev = j;
                if ((int)insertOrder.size() >= (int)winners.size()) break;
            }
            for (int k = (int)winners.size(); (int)insertOrder.size() < (int)winners.size() && k >= 1; --k) {
                if (std::find(insertOrder.begin(), insertOrder.end(), k) == insertOrder.end())
                    insertOrder.push_back(k);
            }
        } else {
            for (int k = 1; k <= (int)winners.size(); ++k) insertOrder.push_back(k);
        }

        // If there's a leftover element, process it as the last item in insertOrder
        if (hasLeftover) {
            insertOrder.push_back((int)winners.size() + 1); // sentinel for leftover
        }

        std::deque<bool> inserted(winners.size(), false);

        // SPECIAL CASE: insert a1 (loser[0]) before b1 without comparison
        if (!losers.empty() && !mainChain.empty()) {
            mainChain.insert(mainChain.begin(), losers[0]);
            inserted[0] = true;
        }

        // Вставляем проигравших в полном Knuth-порядке
        for (size_t ord = 0; ord < insertOrder.size(); ++ord) {
            int val = insertOrder[ord];
            // sentinel value > winners.size() denotes leftover
            if (val == (int)winners.size() + 1) {
                int pos = binaryFindInsertPosDeque(mainChain, leftover, (int)mainChain.size(), comparisons, debug, depth, "insert leftover (in-order)");
                mainChain.insert(mainChain.begin() + pos, leftover);
                continue;
            }

            int idx = val - 1;
            if (idx >= 0 && idx < (int)winners.size() && !inserted[idx]) {
                int winnerPos = 0;
                for (size_t j = 0; j < mainChain.size(); j++) {
                    if (mainChain[j] == winners[idx]) {
                        winnerPos = j;
                        break;
                    }
                }

                int pos = binaryFindInsertPosDeque(mainChain, losers[idx], winnerPos, comparisons, debug, depth, "insert L sequence");
                mainChain.insert(mainChain.begin() + pos, losers[idx]);
                inserted[idx] = true;
            }
        }

        // (leftover will be inserted after all losers — done as final step)
    }


    // FINAL STEP handled via insertOrder when present

    // Заменяем исходный массив
    arr = mainChain;

    if (debug) {
        std::cout << std::string(depth * 2, ' ') << "Result: ";
        for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "Total comparisons: " << comparisons << std::endl;
    }
}

// fordJohnsonSort for deque
void PmergeMe::fordJohnsonSort(std::deque<int>& container, int left, int right) {
    std::deque<int> tmp;
    for (int i = left; i <= right; i++) tmp.push_back(container[i]);

    sortDequeRecursive(tmp, comparisons, debug, 0);

    for (size_t i = 0; i < tmp.size(); i++) container[left + i] = tmp[i];
}
