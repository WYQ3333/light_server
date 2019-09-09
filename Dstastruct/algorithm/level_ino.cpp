#include <iostream>
#include <vector>
using namespace std;

void Ino(vector<int>& array, vector<int>& result, size_t index){
    if(index > array.size())
        return;
    Ino(array, result, 2*index + 1);
    if(index < array.size())
        result.push_back(array[index]);
    Ino(array, result, 2*index + 2);
}

vector<int> solution(vector<int>& array){
    vector<int> result;
    if(array.empty())
        return result;
    Ino(array, result, 0);
    return result;
}

int main()
{
    int size;
    cin >> size;
    vector<int> array;
    for(size_t i = 0; i < size; ++i){
        int temp;
        cin >> temp;
        array.push_back(temp);
    }
    for(size_t i = 0; i < array.size(); ++i){
        cout << array[i] << " "; 
    }
    cout << endl;
    vector<int> result;
    result = solution(array);
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    return 0;
}

