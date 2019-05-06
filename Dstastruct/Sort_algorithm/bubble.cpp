#include <iostream>
#include<vector>
using namespace std;


void BubbleSort(vector<int>& array){
    if(array.empty())
        return;
    for(size_t i = 0; i < array.size(); ++i){
        for(size_t j = i; j < array.size(); ++j){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void BubbleSort2(vector<int>& array){
    if(array.empty())
        return;
    bool flag = false;
    for(size_t i = 0; i < array.size(); ++i){
        for(size_t j = i; j < array.size(); ++j){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                flag = true;
            }
        }
        if(!flag){
            //优化，如果没有交换，直接退出
            break;
        }
    }
}

void BubbleSort3(vector<int>& array){
    if(array.empty())
        return;
    size_t boder = array.size() - 1;
    size_t index = 0;
    for(size_t i = 0; i < array.size(); ++i){
        bool flag = false;
        for(size_t j = i; j <= boder; ++j){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                index = j;  //记录最后一集交换的位置
                flag = true;
            }
        }
        boder = index;
        if(!flag)
            break;
    }
}

int main()
{
    vector<int> array = {1, 3, 2, 4, 5, 9, 8, 6, 7, 0};
    BubbleSort3(array);
    for(size_t i = 0; i < array.size(); ++i){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}

