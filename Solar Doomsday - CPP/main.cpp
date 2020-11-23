 /*
  Eric Meehan
  2020-11-23
  
  Solar Doomsday
 */

#include <iostream>
#include <math.h>
#include <string>
#include "CustomArray.hpp"


int main(int argc, const char * argv[]) {
    // The user may specify the initial size of the solar material through a command line argument
    int TotalArea;
    if (argc > 1)
    {
        try
        {
            // This argument will need to be cast as an integer
            std::string arg = argv[1];
            TotalArea = std::stoi(arg);
        }
        catch (std::invalid_argument)
        {
            std::cout << "Invalid input, using default value of 15324" << std::endl;
            TotalArea = 15324;
        }
    }
    else
    {
        TotalArea = 15324;
    }
    // Use the custom array class to hold all of the values
    CustomArray<int> Results;
    double Panel;
    // Each panel will be the square root of the remaining area, rounded down to the nearest integer
    while (TotalArea > 0)
    {
        Panel = floor(sqrt(TotalArea));
        TotalArea -= pow(Panel, 2);
        Results.Append(pow(Panel, 2));
    }
    // Print the results
    std::cout << Results << std::endl;
    return 0;
}
