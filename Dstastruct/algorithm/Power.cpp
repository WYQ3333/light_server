#include <iostream>
//求base的exponent次方，求解思路考虑base为0的情况，以及exponent为负数的情况，分开讨论
class Solution {
public:
	double Power(double base, int exponent) {
        double result=base;
        if (base == 0.0){
			return 0;
		}
		if (base == 1){
			return 1;
		}
		if (exponent == 0){
			return 1;
		}
		else if (exponent > 0){
			if (base != 0 && base != 1){
				int i = exponent;
				while (i - 1){
					result *= base;
					--i;
				}
				return result;
			}
		}
		else if (exponent < 0){
			if (base != 0 && base != 1){
				double temp = base;
                result = temp;
				int i = 0-exponent;
				while (i - 1){
					result *= temp;
					--i;
				}
                result=1/result;
			}
		}
        return result;
	}
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

