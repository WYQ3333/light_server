#include <iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct num{
    int uper;
    int down;
    num()
        :uper(0)
        ,down(0)
    {}
    bool operator>(const num& temp){
        return down > temp.down;
    }
    void operator=(const num& temp){
        uper = temp.uper;
        down = temp.down;
    }
    void operator+=(const num& temp){
        uper = uper*temp.down + down*temp.uper;
        down = down*temp.down;
    }
}num;

bool cmp(const num& a, const num& b){
    return a.down < b.down;
}

class Solution{
public:

    int find_max_divisor(int num1, int num2){
        if(num1 == 0){
            return 0;
        }
        if(num2 == 1){
            return 1;
        }
        if(num1 < num2)
            swap(num1, num2);
        int result = -1;
        for(size_t i = 2; i <= num2; ++i){
            if(num1%i == 0 && num2%i == 0){
                result = i;
            }
        }
        return result;
    }

    /* num addfraction(const num& a, const num& b){ */
    /*     num result; */
    /*     result.down = a.down*b.down; */
    /*     result.uper = a.uper*b.down + b.uper*a.down; */
    /*     return result; */
    /* } */

    string fractionAddition(string expression){
        if(expression.empty())
            return "";
        vector<num> array;
        for(size_t i = 0; i < expression.size(); ++i){
            num numbers;
            if(expression[i] == '/'){
                int left = i - 1;
                string temp;
                while(left >= 0 && (expression[left] != '-' && expression[left] != '+')){
                    temp += expression[left];
                    left--;
                }
                reverse(temp.begin(), temp.end());
                numbers.uper = atoi(temp.c_str());
                if(left >= 0 && expression[left] == '-'){
                    numbers.uper = -numbers.uper;
                }
                temp.clear();
                int right = i + 1;
                while(right < expression.size() && (expression[right] != '-' && expression[right] != '+')){
                    temp += expression[right];
                    right++;
                }
                numbers.down = atoi(temp.c_str());
                array.push_back(numbers);
            }
        }
        sort(array.begin(), array.end(), cmp);
        //for(size_t i = 0; i < array.size(); ++i){
        //    cout << array[i].uper << "/" << array[i].down << endl;
        //}
        num answer = array[0];
        for(size_t i = 1; i < array.size(); ++i){
            answer += array[i];
        }
        int the_divisor = find_max_divisor(abs(answer.uper), answer.down);
        //cout << "the_divisor " << the_divisor << endl;
        if(the_divisor == 0){
            answer.down = 1;
        }
        else if(the_divisor > 1){
            answer.uper /= the_divisor;
            answer.down /= the_divisor;
        }
        //cout << "-------------answer---------------" << endl;
        //cout << answer.uper << "/" << answer.down << endl;

        string the_result = "";
        the_result += to_string(answer.uper);
        the_result += '/';
        the_result += to_string(answer.down);
        return the_result;
    }
};

int main()
{
    Solution s;
    string temp;
    cin >> temp;
    cout << s.fractionAddition(temp) << endl;

    return 0;
}

