#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    bool canReorderDoubled2(vector<int>& array){
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
    bool find_2_num(vector<int>& array, int pos, int num, size_t& index){
        for(size_t i = pos; i < array.size(); ++i){
            if(array[i] == 2*num){
                index = i;
                return true;
            }
            else if(num == 2*array[i]){
                index = i - 1;
                return true;
            }
        }
        return false;
    }
    bool canReorderDoubled(vector<int>& array){
        if(array.size() == 0){
            return true;
        }
        for(size_t i = 0; i < array.size(); ++i){
            if(array[i] < 0){
                array[i] = -array[i];
            }
        }
        size_t index = 0;
        size_t ret_index = 0;
        while(index < array.size()){
            if(find_2_num(array, index + 1, array[index], ret_index)){
                if(ret_index != index + 1)
                    swap(array[index + 1], array[ret_index]);
                index += 2;
            }
            else{
                return false;
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
    vector<int> array = {4,-4,4,-2,-4,-8};
    s.Print(array);
    cout << s.canReorderDoubled(array) << endl;
    s.Print(array);
    return 0;
}

