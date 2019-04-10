#include <iostream>

// 每月天数，不考虑闰年，从 0 开始
inline int day_of_month(int m) {
    const static int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return days[m];
}
// 判断是否是闰年
inline bool leap_year(int y) {
    if (y % 4 == 0 && y % 100 != 0) {
        return true;
    }
    if (y % 400 == 0) {
        return true;
    }
    return false;
}
// 一年的收益，不考虑闰年
inline int profit_of_year() {
    return 2 * 31
        + 1 * 28
        + 1 * 31
        + 2 * 30
        + 1 * 31
        + 2 * 30
        + 1 * 31
        + 2 * 31
        + 2 * 30
        + 2 * 31
        + 1 * 30
        + 2 * 31;
}
// 判断月份是否是素数，从 0 开始
inline bool prime(int m) {
    const static bool p[] = { false, true, true, false, true, false, true, false, false,
        false, true, false };
    return p[m];
}
int main(){
    int year1, month1, day1, year2, month2, day2;
    while (std::cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
    {
        int profit = 0;
        int year = year1;
        // 计算完整年份的收益
        for (int y = year1; y <= year2 - 1; ++y)
        { profit += profit_of_year();
            if (leap_year(y))
            { 
                profit += 1;
            }
        }
        // 减去多计算的 year1 从 1月(0) 到 month1 的收益
        for (int m = 0; m < month1; ++m)
        { int days;
            if (m == month1 - 1) {
                // 这个月不完整
                days = day1 - 1;
            } else {
                days = day_of_month(m);
                if (m == 1 && leap_year(year1))
                { 
                    days += 1;
                }
            }
            int profit_of_month = days * (prime(m) ? 1 : 2);
            profit -= profit_of_month;
        }
        // 加上少计算的 year2 从 1月(0) 到 month2 的收益
        for (int m = 0; m < month2; ++m)
        { int days;
            if (m == month2 - 1) {
                // 这个月不完整
                days = day2;
            } else {
                days = day_of_month(m);
                if (m == 1 && leap_year(year2))
                { 
                    days += 1;
                }
            }
            int profit_of_month = days * (prime(m) ? 1 : 2);
            profit += profit_of_month;
        }
        std::cout << profit << '\n';
    }
    return 0;
}
