#include <iostream>
#include <fstream>
#include <cstdlib>

/*prototypes*/
std::string getOutfileName(std::string infile);
void findAndReplace(std::ifstream& infile, std::ofstream& outfile, std::string s1, std::string s2);
std::string replace(std::string line, std::string s1, std::string s2);


int main(int argc, char **argv)
{

	if (argc != 4)
	{
		std::cout
			<< "Required params: filename s1 s1" << std::endl;
		std::exit(1);
	}
	std::ifstream infile(argv[1]);
	if (infile.is_open())
	{
		std::ofstream outfile(getOutfileName(argv[1]).c_str());
		if (outfile.is_open())
			findAndReplace(infile, outfile, argv[2], argv[3]);
		else 
		{
			std::cout
				<< "Unknown error creating file " << getOutfileName(argv[1]) << std::endl;
			std::exit(3);
		}
	}
	else 
	{
		std::cout
			<< "Unknown error opening file " << argv[1] << std::endl;
		std::exit(2);
	}
}

std::string replace(std::string line, std::string s1, std::string s2)
{
	std::string replaced_line;

	for (size_t i = 0; i < line.length(); i++)
	{
		if (line.substr(i, s1.length()) == s1)
		{
			replaced_line.append(s2);
			i += s1.length() - 1;
		}
		else 
			replaced_line += line[i];
	}	
	return (replaced_line);
}

void findAndReplace(std::ifstream& infile, std::ofstream& outfile, std::string s1, std::string s2)
{
	std::string line;

	while (std::getline(infile, line, '\n'))
		outfile << replace(line, s1, s2) << std::endl;
}

std::string getOutfileName(std::string infile)
{
	infile.append(".replace");
	return (infile);
}
