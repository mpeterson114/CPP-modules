#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Usage: ./convert <input arg>" << std::endl;
        return (1);
    }
    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch (ScalarConverter::InvalidType &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}
