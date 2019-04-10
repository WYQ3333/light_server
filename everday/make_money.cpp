#include <iostream>
using namespace std;

int profit_begin_to_month(int yeart, int montht, int dayst, int *monthofday){
    int profit = 0;
    monthofday[2] = ((yeart%4 == 0 && yeart%100 != 0) || (yeart%400 == 0)) ? 29 : 28;
    for(int i = 1; i < montht; ++i){
        if(i == 2 || i == 3 || i == 5 || i == 7 || i ==11){
            profit += monthofday[i];
        }
        else{
            profit += monthofday[i]*2;
        }
    }
    if(montht == 2 || montht == 3 || montht == 5 || montht == 7 || montht ==11){
        profit += dayst;
    }
    else{
        profit += dayst*2;
    }
    return profit;
}

int profit_to_yearslast(int yearf, int monthf, int daysf, int *monthofday){
    int profit = 0; 
    monthofday[2] = ((yearf%4 == 0 && yearf%100 != 0) || (yearf%400 == 0)) ? 29 : 28;
    for(int i = monthf; i < 13; ++i){
        if(i == 2 || i == 3 || i == 5 || i == 7 || i ==11){
            profit += monthofday[i];
        }
        else{
            profit += monthofday[i]*2;
        }
    }

    if(monthf == 2 || monthf == 3 || monthf == 5 || monthf == 7 || monthf ==11){
        profit -= daysf - 1;
    }
    else{
        profit -= (daysf - 1)*2;
    }

    return profit;
}

int profit_to_month(int yearf, int monthf, int daysf, int yeart, int montht, int dayst, int *monthofday){
    int profit = 0;
    if(yearf == yeart){
        monthofday[2] = ((yearf%4 == 0 && yearf%100 != 0) || (yearf%400 == 0)) ? 29 : 28;
        if(monthf == montht){
            if(monthf == 2 || monthf == 3 || monthf == 5 || monthf == 7 || monthf == 11){
                profit += dayst - daysf + 1;
            }
            else{
                profit += (dayst - daysf + 1)*2;
            }
        }
        else{
            for(int i = monthf; i < montht; ++i){
                if(i == 2 || i == 3 || i == 5 || i == 7 || i == 11){
                    profit += monthofday[i];
                }
                else{
                    profit += monthofday[i]*2;
                }
            }

            if(montht == 2 || montht == 3 || montht == 5 || montht == 7 || montht ==11){
                profit += dayst;
            }
            else{
                profit += dayst*2;
            }

            if(monthf == 2 || monthf == 3 || monthf == 5 || monthf == 7 || monthf ==11){
                profit -= daysf - 1;
            }
            else{
                profit -= (daysf - 1)*2;
            }
        }
    }
    else{
        //year is not equal
        for(int i = yearf + 1; i < yeart; ++i){
            profit += profit_to_yearslast(i, 1, 1, monthofday);
        }
        profit += profit_to_yearslast(yearf, monthf, daysf, monthofday);
        profit += profit_begin_to_month(yeart, montht, dayst, monthofday);
    }
    return profit;
}

int solution(int yearf, int monthf, int daysf, int yeart, int montht, int dayst){
    int monthofday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int profit = 0;
    profit = profit_to_month(yearf, monthf, daysf, yeart, montht, dayst, monthofday);
    return profit;
}

int main()
{
    int yearf, monthf, daysf, yeart, montht, dayst;
    while(cin >> yearf >> monthf >> daysf >> yeart >> montht >> dayst){
        cout << solution(yearf, monthf, daysf, yeart, montht, dayst) << endl;
    }
    return 0;
}

