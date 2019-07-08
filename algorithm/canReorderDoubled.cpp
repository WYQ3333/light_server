#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    bool canReorderDoubled(vector<int>& array){
        if(array.size() == 0){
            return true;
        }
        for(size_t i = 0; i < array.size(); ++i){
            if(array[i] < 0){
                array[i] = -array[i];
            }
        }
        sort(array.begin(), array.end());
        size_t index = 0;
        for(size_t i = 1; i < array.size();){
            if(2 * array[index] == array[i] || array[index] == 2*array[i]){
                if(index + 1 < array.size())
                    swap(array[i], array[index + 1]);
                index += 2;
                i = index + 1;
            }
            else if(i == array.size() -1 && array[i] != 2*array[index]){
                return false;
            }
            else{
                i++;
            }
        }
        return true;
    }

    void Print(vector<int>& array){
        for(size_t i = 0; i < array.size(); ++i){
            cout << array[i] << " " ;
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    //vector<int> array = {4,-2,2,-4};
    vector<int> array = {-2,-6,-3,4,-4,2};
    s.Print(array);
    cout << s.canReorderDoubled(array) << endl;
    s.Print(array);
    return 0;
}

