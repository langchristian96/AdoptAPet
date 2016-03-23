#include "Utils.h"
#include <sstream>
#include <string>

using namespace std;

std::string trim(const std::string& s)
{
	std::string result(s);
	int pos = result.find_first_not_of(" ");
	if (pos != -1)
		result.erase(0, pos);
	pos = result.find_last_not_of(" ");
	if (pos != std::string::npos)
		result.erase(pos + 1);

	return result;
}

void tokenize(std::string str, char delimiter, std::string tokens[], int& length)
{
	length = 0;
	stringstream linestream(str);
	string item{};
	while (getline(linestream, item, delimiter))
	{
		tokens[length++] = trim(item);
	}
}