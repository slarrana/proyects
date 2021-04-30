#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int	put_word(std::string line, std::string word, std::string replace, std::ofstream *ofs)
{
	std::string	str;
	int		i;

	i = 0;
	while (i < line.length())
	{
		if (line.at(i) == ' ' || line.at(i) == '\t')
			break ;
		i++;
	}
	str = line.substr(0, i);
	if (str == word)
		*ofs << replace;
	else
		*ofs << str;
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 4)
	{
		std::cout << "Error, numero de argumentos erroneo" << std::endl;
		return (-1);
	}
	if (std::string(argv[1]) == "" || std::string(argv[2]) == "" || std::string(argv[3]) == "")
	{
		std::cout << "Error, string vacio" << std::endl;
		return (-1);
	}
	std::ifstream ifs(argv[1]);
	std::ofstream ofs("replace.txt");
	std::string line;
	while (getline(ifs, line))
	{
		i = 0;
		while (line[i])
		{
			if (line[i] == ' ' || line[i] == '\t')
				ofs << line[i++];
			else
				i += put_word(&line[i], std::string(argv[2]), std::string(argv[3]), &ofs);
		}
		ofs << std::endl;
	}
	ifs.close();
	ofs.close();
	return (0);
}



