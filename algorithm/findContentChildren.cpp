#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    int findContentChildren(vector<int>& g, vector<int>& s){
        if(g.empty() || s.empty()){
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;
        int i = 0; 
        int j = 0;
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                i++;
                j++;
                result++;
            }
            else{
                j++;
            }
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> arra = {1, 2, 3};
    vector<int> temp = {1, 2};
    cout << s.findContentChildren(arra, temp) << endl;
    return 0;
}

