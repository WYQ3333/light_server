#include <iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution{
public:
    std::string addBinary(std::string a, std::string b){
        std::string result = "";
        if(a.empty() && b.empty()){
            return "";
        }
        if(a.empty() && !b.empty())
            result = b;
        if(!a.empty() && b.empty())
            result = a;
        if(a.size() < b.size()){
            swap(a, b);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        size_t i = 0;
        for(i = 0; i < b.size(); ++i){
            result += to_string((a[i] - '0' + b[i] - '0'));
        }
        result += a.substr(i);
        cout << "result " << result << endl;
        for(i = 0; i < result.size(); ++i){
            if(i < result.size() - 1 && result[i] - '0' > 1){
                result[i + 1] += 1;
                result[i] -= 2;
            }
        }
        if(result[result.size() - 1] - '0' > 1){
            result[result.size() - 1] -= 2;
            result += '1';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    Solution s;
    string input1, input2;
    cin >> input1 >> input2;
    cout << s.addBinary(input1, input2) << endl;
    return 0;
}

