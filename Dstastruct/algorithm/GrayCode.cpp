#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class GrayCode {
public:
    void Two_array(vector<string>& result){
        vector<string> temp;
        for(int i = result.size() - 1; i >= 0; --i){
            temp.push_back(result[i]);
        }
        for(size_t i = 0; i < temp.size(); ++i){
            result.push_back(temp[i]);
        }
    }
    void Two_insert(vector<string>& result){
        for(size_t i = 0; i < result.size(); ++i){
            if(i < result.size()/2){
                result[i] += "0";
            }
            else{
                result[i] += "1";
            }
        }
    }
    vector<string> getGray(int n) {
        // write code here
        vector<string> result;
        if(n <= 0){
            return result;
        }
        result.push_back("0");
        result.push_back("1");
        for(int i = 2; i <= n; ++i){
            Two_array(result);
            Two_insert(result);
        }
        for(size_t i = 0; i < result.size(); ++i){
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

