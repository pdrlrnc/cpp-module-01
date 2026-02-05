#include <iostream>
#include <fstream>
#include <cstdlib>

/*prototypes*/
std::string getOutfileName(std::string infile);
void findAndReplace(std::ifstream& infile, std::ofstream& outfile, std::string s1, std::string s2);


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
		{
			findAndReplace(infile, outfile, argv[2], argv[3]);
		}
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

void findAndReplace(std::ifstream& infile, std::ofstream& outfile, std::string s1, std::string s2)
{
	std::string line;

	while (std::getline(infile, line, s1[0]))
	{
		outfile << line;
		char* replaced_line = new char[s1.length()];
		for (size_t i = 0; i < s1.length(); i++)
		{
			infile.get(replaced_line, 1);
			if (replaced_line[i] != s1[i])
				break;
		}
		if (replaced_line == s1)
			outfile << s2;
		else 
			outfile << replaced_line;
		delete[] replaced_line;
	}

}

std::string getOutfileName(std::string infile)
{
	infile.append(".replace");
	return (infile);
}
