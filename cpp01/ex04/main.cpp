#include <iostream>
#include <fstream>
#include <string>

int replace(char **argv, std::string contents)
{
    std::ofstream outfile;
    int pos;
    int i;

    outfile.open((std::string(argv[1]) + ".replace").c_str());
    if (outfile.fail())
        return (1);
    i = 0;
    while (i < (int)contents.size())
    {
        pos = contents.find(argv[2], i);
        if (pos != (int)std::string::npos && pos == i)
        {
            outfile << argv[3];
            i += std::string(argv[2]).size() - 1;
        }
        else
            outfile << contents[i];
        i++;
    }
    outfile.close();
    return (0);
}

int main(int argc, char **argv)
{
    std::ifstream infile;
    std::string contents;
    char c;

    if (argc != 4)
    {
        std::cout << "Wrong number of arguments." << std::endl;
        std::cout << "Usage: '" << argv[0] << " <filename> \"text to replace\" \"replacement text\"'." << std::endl;
        return (1);
    }
    else
    {
        if (!argv[2][0] || !argv[3][0])
        {
            std::cout << "Error: input strings cannot be empty" << std::endl;
            return (1);
        }
        infile.open(argv[1]);
        if (infile.fail())
        {
            std::cout << "Error, failed to open file: " << argv[1] << std::endl;
            return (1);
        }
        while (!infile.eof() && infile >> std::noskipws >> c)
            contents += c;
        infile.close();
        return (replace(argv, contents));
    }

}