#include <string>
#include <fstream>
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "error: argument" << std::endl;
		return (1);
	}

	std::string	line;
	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	std::ifstream	inputFile(filename);
	if (!inputFile.is_open())
	{
		std::cout << "error: file" << std::endl;
		return (1);
	}
	std::ofstream	outputFile(filename + ".replace");
	if (!inputFile.is_open())
	{
		std::cout << "error: file" << std::endl;
		return (1);
	}

	while (true)
	{
		std::getline(inputFile, line);
		size_t	pos = 0;
		while (true)
		{
			pos = line.find(s1, pos);
			if (pos == std::string::npos)
				break ;
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		outputFile << line;
		if (inputFile.eof())
			break ;
		outputFile << std::endl;
	}

	inputFile.close();
	outputFile.close();
	return (0);
}
