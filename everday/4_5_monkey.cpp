#include <iostream>
#include <string>
#include <math.h>
int main()
{
    int n;
    while(std::cin >> n) {
        int total = pow(5, n) - 4;
        int left = pow(4, n) + n - 4;
        std::cout << total << " " << left << std::endl;
    }
    return 0;
}


