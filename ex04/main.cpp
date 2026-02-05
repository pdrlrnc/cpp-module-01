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

void findAndReplace(std::ifstream& infile, std::ofstream& outfile, std::string s1, std::string s2)
{
	std::string line;
	std::string replace_line;
	char *c = new char[2];

	while (std::getline(infile, line, s1[0]))
	{
		outfile << line;
		c[0] = s1[0];
		c[1] = '\0';
		replace_line.append(c);
		infile.get(c, 2);
		for (size_t i = 1; i < s1.length(); i++)
		{
			if (*c != s1[i])
				break;
			replace_line.append(c);
			infile.get(c, 2);
		}
		if (replace_line == s1)
			outfile << s2;
		else 
			outfile << replace_line;
		replace_line.clear();
	}
	delete[] c;

}

std::string getOutfileName(std::string infile)
{
	infile.append(".replace");
	return (infile);
}
