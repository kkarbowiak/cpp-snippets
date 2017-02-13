#include <string>
#include <fstream>
#include <sstream>

#include <iostream>

std::string getFileContent(std::string const & file_name)
{
    std::ifstream ifs(file_name.c_str());
    std::stringstream ss;
    ss << ifs.rdbuf();

    return ss.str();
}

int main()
{
    std::string const file = "text.txt";

    std::cout << "File " << file << " is:\n-->\n" << getFileContent(file) << "<--" << std::endl;

    return 0;
}

