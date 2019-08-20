#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    Solution(){
        for(int i = 0; i < 256; ++i){
            array[i] = -1;
        }
    }
  //Insert one char from stringstream
    void Insert(char ch)
    {
         array[ch]++;
        data.push_back(ch);
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch = '#';
        for(int i = 0; i < data.size(); ++i){
            if(array[data[i]] == 0){
                return data[i];
            }
        }
        return ch;
    }
    char array[256];
    vector<char> data;
};
int main()
{
    return 0;
}

