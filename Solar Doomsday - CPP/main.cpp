 /*
  Eric Meehan
  2020-11-23
  
  Solar Doomsday
 */

#include <iostream>
#include <math.h>
#include <vector>


int main(int argc, const char * argv[]) {
    std::vector<int> Results;
    int TotalArea = 15324;
    double Panel;
    while (TotalArea > 0)
    {
        Panel = floor(sqrt(TotalArea));
        TotalArea -= pow(Panel, 2);
        Results.push_back(pow(Panel, 2));
    }
    for (auto each : Results)
    {
        std::cout << each << " ";
    }
    std::cout << std::endl;
    return 0;
}
