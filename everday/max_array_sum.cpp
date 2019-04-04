#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> array = {1, -1, 2, 4, -5, 6};
    int max_sum = 0;
    int temp = 0;
    for(size_t i = 0; i < array.size(); ++i){
        temp += array[i];
        if(temp > max_sum){
            max_sum = temp;
        }
        else{
            temp = array[i];
        }
    }
    cout << max_sum << endl;
    return 0;
}

