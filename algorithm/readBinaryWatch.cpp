#include <iostream>
#include<vector>
#include<string>

using namespace std;
class Solution {
public:
    
    int Bit_one_num(int num){
        int count = 0;
        for(size_t i = 0; i < sizeof(int)*8 - 1; ++i){
            if(num & 1 == 1)
                count++;
            num >>= 1;
        }
        return count;
    }
    
    vector<string> readBinaryWatch(int num) {
        int sum = 24*60;
        cout << sum << endl;
        vector<string> result;
        for(int i = 0; i < sum; ++i){
            int hour = 0;
            int minute = 0;
            int se = 0;
            int size = Bit_one_num(i);
            if(size==1)
                cout << "i " << i << " bit " << size << " " << endl;
            if(size == num){
                int temp = i;
                string th = "";
                if(temp >= 60){
                    hour = temp / 60;
                    temp %= 60;
                    th += to_string(hour);
                }
                if(th.empty())
                    th += '0';
                string tm = "";
                if(temp < 60 && temp >= 0){
                    minute = temp/60;
                    tm += to_string(minute);
                }
                if(tm.empty())
                    tm += "00";
                /* string ts = ""; */
                /* if(temp >= 0 && temp < 60){ */
                /*     se = temp; */
                /*     temp %= 60; */
                /*     ts += to_string(se); */
                /* } */
                /* if(ts.empty()){ */
                /*     ts += '0'; */
                /* } */
                
                string answer = th + ':' + tm;
                result.push_back(answer);
                /* if(result.empty()) */
                /*     result.push_back(answer); */
                /* else if(result.back() != answer) */
                /*     result.push_back(answer); */
            }
        }
        return result;
    }
};
int main()
{
    Solution s;
    int input;
    cin >> input;
    cout << "bite num of 1 " << s.Bit_one_num(input) << endl;
    vector<string> result = s.readBinaryWatch(input);
    for(size_t i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

