/*
 Eric Meehan
 2020-11-23
 
 Solar Doomsday - CustomArray
*/

#ifndef CustomArray_hpp
#define CustomArray_hpp

#include <iostream>

template <class type>
class CustomArray
{
private:
    int ArraySize;
    type * Contents;
public:
    // CONSTRUCTOR
    CustomArray()
    {
        // Initialize the class to have a size of zero and assign the pointer to an empty array
        ArraySize = 0;
        Contents = new type[0];
    }
    
    // MUTATOR
    void Append(type NewItem)
    {
        // Expands the array size by one and adds a new element to the back
        // Copy the elements of Contents into a temporary location
        type temp[ArraySize];
        for (int i = 0; i < ArraySize; i++)
        {
            temp[i] = Contents[i];
        }
        // Dealocate the current space defined in Contents
        delete Contents;
        // Increase array size
        ArraySize += 1;
        Contents = new type[ArraySize];
        // Copy previous elements back to Contents
        for (int i = 0; i < ArraySize - 1; i++)
        {
            Contents[i] = temp[i];
        }
        // Add the NewItem to the end
        Contents[ArraySize - 1] = NewItem;
    }
    
    // OPERATOR
    friend std::ostream& operator<<(std::ostream& Stream, const CustomArray& Object)
    {
        // Print the contents of Contents formatted as described in the README
        Stream << "[";
        for (int i = 0; i < Object.ArraySize - 1; i++)
        {
            Stream << Object.Contents[i] << ", ";
        }
        Stream << Object.Contents[Object.ArraySize - 1] << "]";
        return Stream;
    }
};

#endif /* CustomArray_hpp */
