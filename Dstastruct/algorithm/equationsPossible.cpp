/*
 *通过并查集实现解决等号与不等号逻辑整体是否为真
 */
#include <iostream>
#include <vector>
using namespace std;

//并查集
class UnionFindSet{
public:
    UnionFindSet(size_t size)
        :_ufs(size, -1)
        {}
    
    int FindRoot(int index){
        while(_ufs[index] >= 0){
            index = _ufs[index];
        }
        return index;
    }
    
    bool Union(int index_1, int index_2){
        int root1 = FindRoot(index_1);
        int root2 = FindRoot(index_2);
        if(root1 == root2)
            return false;
        _ufs[root1] += _ufs[root2];
        _ufs[root2] = root1;
        return true;
    }
    
    size_t Count(){
        size_t count = 0;
        for(auto i : _ufs){
            if(i < 0){
                count++;
            }
        }
        return count;
    }
private:
    vector<int> _ufs;
};


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        if(equations.empty())
            return true;
        UnionFindSet uf(128);
        for(size_t i = 0; i < equations.size(); ++i){
            if(equations[i][1] == '='){
                uf.Union(equations[i][0] - 'a', equations[i][3] - 'a');
            }
        }
        for(size_t i = 0; i < equations.size(); ++i){
            if('!' == equations[i][1]){
                if(uf.FindRoot(equations[i][0] - 'a') == uf.FindRoot(equations[i][3] - 'a'))
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    return 0;
}

