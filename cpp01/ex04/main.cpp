#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "USAGE: " << std::endl;
		std::cout << argv[0] << " <filename> <s1> <s2>" 
		<< std::endl;
		std::cout << "EXAMPLE: " 
		<< std::endl;
		std::cout << argv[0] << " test.txt \"s1\" \"s2\"" 
		<< std::endl << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Error: file not found" << std::endl;
		return 1;
	}
	std::string line;
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string new_file_name = std::string(argv[1]) + ".replace";
	std::ofstream new_file(new_file_name.c_str());
	if (!new_file.is_open())
	{
		std::cout << "Error: file not found" << std::endl;
		return 1;
	}
	while (std::getline(file, line))
	{
		std::string::size_type pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
		new_file << line << std::endl;
	}
	file.close();
	new_file.close();
	std::cout << "File " << new_file_name
	<< " created with the content of "
	<< argv[1] << " with " << s1 << " replaced by "
	<< s2 << std::endl;
	return 0;
		
}