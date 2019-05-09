#include <iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool isOneBitCharacter(std::vector<int>& bits){
        if(bits.empty())
            return false;
        int cur = 0;
        for(size_t i = 0; i < bits.size(); ++i){
            cur = i;
            if(bits[i] == 1){
                i++;
                continue;
            }
        }
        if(cur == bits.size() - 1){
            return true;
        }
        return false;
    }
};

int main()
{
    std::vector<int> array = {1, 0, 0};
    Solution s;
    std::cout << s.isOneBitCharacter(array) << endl;

    std::vector<int> array1 = {1, 0, 1, 0};
    std::cout << s.isOneBitCharacter(array1) << endl;
    
    return 0;
}

