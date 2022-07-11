#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
int main()
{
	std::ifstream file;
	std::string line;
	std::string otRuki;
	std::string allLine;
	int indx = 0;
	int foundCount = 0;
	file.open("Text.txt");
	if (!file)
	{
		std::cerr << "Oops!" << std::endl;
		return 1;
	}
	else
	{
		while (file >> line) {
			allLine += line + " ";
		}
	}
	file.close();

	getline(std::cin, otRuki);

	std::transform(allLine.begin(), allLine.end(), allLine.begin(), tolower);
	std::transform(otRuki.begin(), otRuki.end(), otRuki.begin(), tolower);


	while (indx < allLine.length()) {
		std::size_t found = allLine.find(otRuki, indx);
		if (found != std::string::npos) {
			indx = found + otRuki.length();
			foundCount++;
		}
		else {
			break;
		}
	}


	std::cout << foundCount;

	return 0;
}