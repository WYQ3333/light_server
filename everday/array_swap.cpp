#include <iostream>
#include<vector>
using namespace std;


int main()
{
    vector<int> array = {1, 2, 3, 4};
    size_t i = 0, j = 1;
    while(i < array.size() && j < array.size()){
        while(i < array.size()&&array[i]%2 == 0){
                i +=2;
        }
        while(j < array.size()&&array[j]%2 != 0){
                j += 2;
        }
        if(i < array.size() && j < array.size()){
            swap(array[i], array[j]);
        }
    }
    for(size_t i = 0; i < array.size(); ++i){
        cout << array[i] << " " ;
    }
    return 0;
}

