#include "Array.hpp"

/* Templates need to be visible to the compiler in every translation
 unit that uses them; compiler generates the code 
 based on the template arguments at compile-time 
 
 .tpp files are not compiled separately like .cpp files, instead
    they're included with the header file 
    
   Default initialization: 
      -Built-in types (int, float, char, etc.) : uninitialized (garbage values)
      -User-defined types (i.e., class with default constructor) :
         default constructor will be called for each element 
   */

void try_tests(Array<int>& arr, int index, std::string msg)
{
   try
   {
      std::cout << msg << index << "]:" << std::endl;
      std::cout << arr[index] << std::endl;
   }
   catch(const std::exception& e)
   {
      std::cerr << e.what() << std::endl;
   }
}

int main()
{
   std::cout << " ________ EMPTY ARRAY ____________ " << std::endl;
   Array<int> empty(0);
   std::cout << "Array size: " << empty.size() << std::endl;
   try_tests(empty, 0, " -> Accessing empty array at index [");
   std::cout << std::endl;

   std::cout << " ________ firstArr TESTS ____________ " << std::endl;
   Array<int> firstArr(5);
   std::cout << "firstArr[] size: " << firstArr.size() << std::endl;
   std::cout << "Contents: " << std::endl;
   for (unsigned int i = 0; i < firstArr.size(); i++)
   {
      firstArr[i] = (i + 1) * 100;
      std::cout << "[" << firstArr[i] << "]" << std::endl;
   }
   std::cout << std::endl;

   try_tests(firstArr, 12, " -> Accessing index [");
   try_tests(firstArr, -42, " -> Accessing index [");
   try_tests(firstArr, 4, " -> Accessing index [");
   try_tests(firstArr, 0, " -> Accessing index [");
   std::cout << std::endl;

   std::cout << " ________ secondArr TESTS (Copy Assignment Operator) ____________ " << std::endl;
   Array<int> secondArr(5);
   std::cout << "secondArr[] size: " << firstArr.size() << std::endl;
   std::cout << "Contents: " << std::endl;
   for (unsigned int i = 0; i < secondArr.size(); i++)
   {
      secondArr[i] = (i + 1);
      std::cout << "[" << secondArr[i] << "]" << std::endl;
   }
   std::cout << std::endl;

   std::cout << "Post- copy assignment from firstArr[]: " << std::endl;
   secondArr = firstArr;
   std::cout << "Updated secondArr[] contents:" << std::endl;
   for (unsigned int i = 0; i < secondArr.size(); i++)
   {
      std::cout << "[" << secondArr[i] << "]" << std::endl;
   }
   std::cout << std::endl;

   std::cout << " ________ thirdArr TESTS (Copy Constructor) ____________ " << std::endl;
   Array<int> thirdArr(secondArr);
   std::cout << "thirdArr[] size: " << thirdArr.size() << std::endl;
   std::cout << "Contents copied from secondArr[]: " << std::endl;
   for (unsigned int i = 0; i < thirdArr.size(); i++)
   {
      std::cout << "[" << thirdArr[i] << "]" << std::endl;
   }
   std::cout << std::endl;

   std::cout << " -> Updating thirdArr values..." << std::endl;
   thirdArr[2] = 42;
   thirdArr[4] = 42;
   std::cout << "Printing thirdArr contents with modifications:" << std::endl;
   for (unsigned int i = 0; i < thirdArr.size(); i++)
   {
      std::cout << "[" << thirdArr[i] << "]" << std::endl;
   }
   std::cout << std::endl;
   std::cout << " ________ CHAR ARRAY TESTS ____________ " << std::endl;
   Array<char> charArr(5);
   for (unsigned int i = 0; i < thirdArr.size(); i++)
   {
      charArr[i] = i + 'a';
      std::cout << "[" << charArr[i] << "]" << std::endl;
   }
   std::cout << std::endl;
   return 0;
}
