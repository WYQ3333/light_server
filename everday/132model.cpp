#include <iostream>
#include<vector>
using namespace std;


bool solution(vector<int>& array){
    for(size_t i = 0; i < array.size(); ++i){
        for(size_t j = i + 1; j < array.size(); ++j){
            for(size_t k = j + 1; k < array.size(); ++k){
                if(array[i] < array[j] && array[i] < array[k] && array[j] > array[k]){
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<int> array;
    int input;
    cin >> input;
    for(int i = 0; i < input; ++i){
        int temp;
        cin >> temp;
        array.push_back(temp);
    }
    cout << solution(array) << endl;
    return 0;
}

