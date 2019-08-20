#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void Insert(int num)
    {
        array.push_back(num);
    }

    double GetMedian()
    { 
        int size = array.size();
        double result = 0;
        sort(array.begin(), array.end());
        if(size % 2 == 0){
            double a = array[size/2];
            double b = array[size/2 - 1];
            result = (a + b)/2;
        }
        else{
            result = array[size/2];
        }
        return result;
    }
vector<int> array;
};
int main()
{
    return 0;
}

