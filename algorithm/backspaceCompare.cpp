#include <iostream>
class Solution {
public:
    void Erase_str(string& S){
        for(int i = 0; i < S.size(); ++i){
            if(i == 0 && S[i] == '#'){
                S.erase(i,1);
                i = -1;
            }
            else if(S[i] == '#'){
                S.erase(i - 1, 2);
                i = -1;
            }
        }
    }
    
    bool backspaceCompare(string S, string T) {
        if(S.empty() && T.empty())
            return true;
        Erase_str(S);
        Erase_str(T);
        cout << T << endl;
        cout << S << endl;
        if(S.size() != T.size())
            return false;
        for(size_t i = 0; i < S.size(); ++i){
            if(S[i] != T[i]){
                return false;
            }
        }
        return true;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

