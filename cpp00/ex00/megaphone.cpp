#include <iostream>

#define NOISE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv)
{
    if (argc == 1) {
        std::cout << NOISE << std::endl;
        return (0);
    }
    else {
        for (int i = 1; i < argc; i++)
		{
            for (int j = 0; argv[i][j]; j++)
                std::cout << (char)toupper(argv[i][j]);
		}
    }
    std::cout << std::endl;
    return (0);
}