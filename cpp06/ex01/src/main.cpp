#include "Serializer.hpp"

/* - Serialization: Converting an object into a format that can easily be stored or 
    transmitted. Allows pointer's address to be saved as an integer 

- Deserialization: Take stored numerical value and convert back to the original
        object (pointer to Data struct in this case) 
        
- Reinterpret_cast: Used to convert one pointer type to another pointer type, or
    to convert pointer types to integer types (or vice versa)
    - No type safety checks, can be very risky

- Here, converting pointer to an unsigned int of size 64 bits (large enough to store memory address)
*/

int main()
{
    Data* data = new Data;
    data->value = 100;
    
    uintptr_t rawData = Serializer::serialize(data);
    Data* returnData = Serializer::deserialize(rawData);

    std::cout << "Original 'data' pointer address: " << data << std::endl;
    std::cout << "Original data->value: " << data->value << std::endl;
    std::cout << std::endl;
    std::cout << "Pointer to data structure serialized as 'int': " << rawData << std::endl;
    std::cout << std::endl;
    std::cout << "New 'returnData' pointer from rawData: " << returnData << std::endl;
    std::cout << "New returnData->value: " << returnData->value << std::endl;
    std::cout << std::endl;

    if (returnData == data)
        std::cout << "Serialization/Deserialization success! " << std::endl;
    else
        std::cout << "Failure!" << std::endl;
    std::cout << std::endl;

    delete data;
    return (0);
}
