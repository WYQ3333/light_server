#include <iostream>
#include<stack>
#include<vector>
/* using namespace std; */ 

class Solution_false{
public:
    int n_n(int n){
        int result = 1;
        for(int i = 0; i < n; ++i){
            result *= 2;
        }
        return result;
    }
    std::vector<int> grayCode(int n){
        std::vector<int> result;
        if(n == 0){
            result.push_back(0);
            return result;
        }
        if(n < 0){
            return result;
        }
        for(size_t i = 0; i < n_n(n); ++i){
            result.push_back(i);
        }
        for(size_t i = 3; i < n_n(n); i += 4){
            int temp = result[i];
            result[i] = result[i-1];
            result[i-1] = temp;
        }
        return result;
    }
};

class Solution_stack{
public:
    int n_n(int n){
        if(n == 1){
            return 2;
        }
        int result = 1;
        for(int i = 0; i < n; ++i){
            result *= 2;
        }
        return result;
    }
    std::vector<int> grayCode(int n){
        std::vector<int> result;
        if(n < 0){
            return result;
        }
        if(n == 0){
            result.push_back(0);
            return result;
        }
        result.push_back(0);
        result.push_back(1);
        int border = n_n(n);
        std::stack<int> s1;
        while(result.size() < border){
            for(size_t i = 0; i < result.size(); ++i){
                s1.push(result[i]);
            }
            int temp = result.size();
            while(s1.size()){
                int index = 0;
                index = s1.top() + temp;
                s1.pop();
                result.push_back(index);
            }
        }
        return result;
    }
};

class Solution{
public:
    std::vector<int> grayCode(int n){
        int size = 1 << n;
        std::vector<int> array;
        if(n == 0){
            array.push_back(0);
            return array;
        }
        for(int i = 0; i < size; ++i){
            int temp = i^(i >> 1);
            array.push_back(temp);
        }
        return array;
    }
};
int main()
{
    Solution s;
    std::vector<int> array;
    array = s.grayCode(1);
    for(size_t i = 0; i < array.size(); ++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
    
    array = s.grayCode(2);
    for(size_t i = 0; i < array.size(); ++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    array = s.grayCode(3);
    for(size_t i = 0; i < array.size(); ++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

