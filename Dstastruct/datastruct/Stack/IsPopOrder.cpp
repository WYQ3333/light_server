#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution{
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV){
        if(pushV.size() != popV.size()){
            return false;
        }
        int index_push = 0;
        int index_pop = 0;
        int size = pushV.size();
        stack<int> s;
        while(index_push < size){
            s.push(pushV[index_push]);
            index_push++;
            while(!s.empty() && s.top() == popV[index_pop]){
                s.pop();
                index_pop++;
            }
        }
        if(s.empty()){
            return true;
        }
        return false;
    }
};

int main()
{
    Solution sl;
    vector<int> temp1 = {1, 2, 3, 4, 5, 6};
    vector<int> temp2 = {1, 4, 2, 3, 5, 6};
    cout << sl.IsPopOrder(temp1, temp2) << endl;
    return 0;
}

