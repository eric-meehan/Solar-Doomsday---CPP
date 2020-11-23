 /*
  Eric Meehan
  2020-11-23
  
  Solar Doomsday
 */

#include <iostream>
#include <math.h>
#include "CustomArray.hpp"


int main(int argc, const char * argv[]) {
    CustomArray<int> Results;
    int TotalArea = 15324;
    double Panel;
    while (TotalArea > 0)
    {
        Panel = floor(sqrt(TotalArea));
        TotalArea -= pow(Panel, 2);
        Results.Append(pow(Panel, 2));
    }
    std::cout << Results << std::endl;
    return 0;
}
