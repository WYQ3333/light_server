#include <iostream>
#include<vector>
#include<string>
using namespace std;

int anwer_days1(int year, int *month_days, int count1, int month){
    int answer = 0;
    int y = (year)/100;
    int c = (year)%100;
    int count = 0;
    int month1 = month;
    if(month > 12){
        month1 = month - 12;
    }
    for(int j = 1; j <= month_days[month1]; ++j){
        int cur = (y + y/4 + c/4 - 2*c + 26*(month + 1)/10 + j -1)%7;
        if(cur == 1){
            count++;
            if(count == count1){
                answer = j;
                break;
            }
        }
    }
    return answer;

}

int anwer_days_last_1(int year, int *month_days, int month){
    int answer = 0;
    int y = (year)/100;
    int c = (year)%100;
    cout << y << " " << c << endl;
    for(int j = month_days[month]; j > 0 ; --j){
        int cur = ((y + y/4 + c/4 - 2*c + 26*(month + 1)/10 + j -1)%7 + 7)%7;
        cout << cur << " " ;
        if(cur == 1){
            answer = j;
            break;
        }
    }
    cout <<endl;
    return answer;
}
int anwer_days_first_1(int year, int *month_days, int month){
    int answer = 0;
    int y = (year)/100;
    int c = (year)%100;
    for(int j = 1; j < month_days[month]; ++j){
        int cur = ((y + y/4 + c/4 - 2*c + 26*(month + 1)/10 + j -1)%7 + 7)%7;
        if(cur == 1){
            answer = j;
            break;
        }
    }
    return answer;
}

void solution(vector<string>& array, int year){
    int answer = 0;
    int month_days[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    month_days[2] = (((year%4 == 0)&& (year%100 != 0))||(year%400 == 0)) ? 29 : 28;
    string temp = "";
    temp = to_string(year) + "-" + "01" "-" + "01";
    array.push_back(temp);
    for(int i = 1; i < 13; ++i){
        temp = "";
        if(i == 1 || i == 2){
            answer = anwer_days1(year-1, month_days, 3, i + 12);
            temp = to_string(year) + "-" + "0" + to_string(i) + "-" + to_string(answer);
            array.push_back(temp);
        }
        else if(i == 5){
            answer = anwer_days_last_1(year, month_days, i);
            if(answer < 10){
                temp = to_string(year) + "-" + "0" + to_string(i) + "-" + "0" + to_string(answer);
            }
            else
                temp = to_string(year) + "-" + "0" + to_string(i) + "-" + to_string(answer);
            array.push_back(temp);
        }
        else if(i == 7){
            temp = to_string(year) + "-" + "07" + "-" + "04";
            array.push_back(temp);
        }
        else if(i == 9){
            answer = anwer_days1(year, month_days, 1, i);
            if(answer < 10){
                temp = to_string(year) + "-" + "0" + to_string(i) + "-" + "0" + to_string(answer);
            }
            else
                temp = to_string(year) + "-" + "0" + to_string(i) + "-" + to_string(answer);
            array.push_back(temp);
        }
        else if(i == 11){
            answer = anwer_days1(year, month_days, 4, i);
            temp = to_string(year) + "-" + to_string(i) + "-" + to_string(answer);
            array.push_back(temp);
        }
        else if(i == 12){
            temp = to_string(year) + "-" + "12" + "-" + "25";
            array.push_back(temp);
        }
    }
}

int main()
{
    int year;
    vector<string> array;
    while(cin >> year){
        solution(array, year);
        for(size_t i = 0; i < array.size(); ++i){
            cout << array[i] << endl;
        }
        array.clear();

    }
    return 0;
}

