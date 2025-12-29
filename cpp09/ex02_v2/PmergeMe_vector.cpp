// PmergeMe_vector.cpp
#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Non-template helpers for std::vector<int>
static int binaryFindInsertPosVector(const std::vector<int>& cont, const int& value, int limit, int &comparisons, bool debug, int depth = 0, const std::string& tag = "") {
    int left = 0;
    int right = limit - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        comparisons++;
        if (debug) {
            std::cout << std::string(depth * 2, ' ') << "Comparison " << comparisons
                      << " (" << tag << "): cont[" << mid << "]=" << cont[mid]
                      << " < value=" << value << " -> ";
        }
        if (cont[mid] < value) {
            if (debug) std::cout << "true" << std::endl;
            left = mid + 1;
        } else {
            if (debug) std::cout << "false" << std::endl;
            right = mid - 1;
        }
    }
    return left;
}

static void sortVectorRecursive(std::vector<int>& arr, int& comparisons, bool debug, int depth = 0) {
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
    std::vector<std::pair<int, int> > pairs; // (больший, меньший)
    std::vector<int> winners;

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
    sortVectorRecursive(winners, comparisons, debug, depth + 1);

    // Шаг 3: Восстановление проигравших в правильном порядке
    std::vector<int> losers(winners.size());
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
    std::vector<int> mainChain;

    // Инициализируем основную цепочку всеми отсортированными победителями
    if (!winners.empty()) {
        mainChain = winners; // start chain with all winners in sorted order
    }

    // Шаг 5: Вставка проигравших в порядке Якобсталя
    if (winners.size() > 1) {
        // Генерируем последовательность Якобсталя для индексов проигравших
        std::vector<int> jacob = PmergeMe::generateJacobsthal(winners.size() - 1);

        std::vector<bool> inserted(winners.size(), false);

        // Шаг 6: Вставка непарного элемента
        if (hasLeftover) {
            int pos = binaryFindInsertPosVector(mainChain, leftover, (int)mainChain.size(), comparisons, debug, depth, "insert leftover");
            mainChain.insert(mainChain.begin() + pos, leftover);

            if (debug) {
                std::cout << std::string(depth * 2, ' ') << "Insert leftover "
                          << leftover << " at pos " << pos << std::endl;
            }
        }

        // Вставляем проигравших в порядке Якобсталя
        for (size_t i = 0; i < jacob.size(); i++) {
            int idx = jacob[i] - 1; // L3 -> idx=2, L2 -> idx=1, ...
            if (idx >= 0 && idx < (int)winners.size() && !inserted[idx]) {
                // Находим позицию победителя
                int winnerPos = 0;
                for (size_t j = 0; j < mainChain.size(); j++) {
                    if (mainChain[j] == winners[idx]) {
                        winnerPos = j;
                        break;
                    }
                }

                // Вставляем проигравшего ПЕРЕД победителем
                int pos = binaryFindInsertPosVector(mainChain, losers[idx], winnerPos, comparisons, debug, depth, "insert L sequence");

                mainChain.insert(mainChain.begin() + pos, losers[idx]);
                inserted[idx] = true;

                if (debug) {
                    std::cout << std::string(depth * 2, ' ') << "Insert L" << (idx+1)
                              << "=" << losers[idx] << " before W" << (idx+1)
                              << " at pos " << pos << std::endl;
                }
            }
        }

        // Вставляем оставшихся проигравших в обратном порядке
        for (int i = winners.size() - 1; i >= 0; i--) {
            if (!inserted[i]) {
                int winnerPos = 0;
                for (size_t j = 0; j < mainChain.size(); j++) {
                    if (mainChain[j] == winners[i]) {
                        winnerPos = j;
                        break;
                    }
                }

                int pos = binaryFindInsertPosVector(mainChain, losers[i], winnerPos, comparisons, debug, depth, "insert remaining");

                mainChain.insert(mainChain.begin() + pos, losers[i]);

                if (debug) {
                    std::cout << std::string(depth * 2, ' ') << "Insert remaining L" << (i+1)
                              << "=" << losers[i] << " before W" << (i+1)
                              << " at pos " << pos << std::endl;
                }
            }
        }
    }


    // Заменяем исходный массив
    arr = mainChain;

    if (debug) {
        std::cout << std::string(depth * 2, ' ') << "Result: ";
        for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "Total comparisons: " << comparisons << std::endl;
    }
}

// fordJohnsonSort for vector
void PmergeMe::fordJohnsonSort(std::vector<int>& container, int left, int right) {
    std::vector<int> tmp;
    for (int i = left; i <= right; i++) tmp.push_back(container[i]);

    sortVectorRecursive(tmp, comparisons, debug, 0);

    for (size_t i = 0; i < tmp.size(); i++) container[left + i] = tmp[i];
}
