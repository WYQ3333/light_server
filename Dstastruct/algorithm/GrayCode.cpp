#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class GrayCode {
public:
    void Two_array(vector<string>& result){
        vector<string> temp;
        for(int i = result.size() - 1; i >= 0; --i){
            temp.push_back(result[i]);
        }
        for(size_t i = 0; i < temp.size(); ++i){
            result.push_back(temp[i]);
        }
    }
    void Two_insert(vector<string>& result){
        for(size_t i = 0; i < result.size(); ++i){
            if(i < result.size()/2){
                result[i] += "0";
            }
            else{
                result[i] += "1";
            }
        }
    }
    vector<string> getGray(int n) {
        // write code here
        vector<string> result;
        if(n <= 0){
            return result;
        }
        result.push_back("0");
        result.push_back("1");
        for(int i = 2; i <= n; ++i){
            Two_array(result);
            Two_insert(result);
        }
        for(size_t i = 0; i < result.size(); ++i){
            reverse(result[i].begin(), result[i].end());
        }
        return result;
    }
};

//方法一：递归
//递归的思路就是n位gray码是由n-1位gray码生成，举个例子简单一些：
//比如求n=3的gray码，首先知道n=2的gray码是(00,01,11,10)
//那么n=3的gray码其实就是对n=2的gray码首位添加0或1生成的，添加0后变成(000,001,011,010)
//添加1后需要顺序反向就变成(110,111,101,100)
//组合在一起就是(000,001,011,010,110,111,101,100)

class GrayCode2 {
public:
    vector<string> getGray(int n) {
        // write code here
        vector<string> gray;
        if(n == 1){
            gray.push_back("0");
            gray.push_back("1");
            return gray;
        }
        vector<string> last_gray = getGray(n-1);
        for(int i = 0; i < last_gray.size(); i++)
            gray.push_back("0"+last_gray[i]);
        for(int i = last_gray.size()-1; i >= 0; i--)
            gray.push_back("1"+last_gray[i]);
         
        return gray;
    }
};

//方法二：利用公式G(n) =  n XOR (n/2)，求得gray码的十进制之后再转换成二进制字符串
class GrayCode3 {
public:
    string getbinarystr(int num, int n){
        string binarystr = "";
        while(num){
            int remain = num % 2;
            stringstream ss;
            ss << remain;
            string remainstr;
            ss >> remainstr;
            binarystr = remainstr + binarystr;
            num = num / 2;
            n--;
        }
        while(n--)
            binarystr = "0" + binarystr;
        return binarystr;
    }
    vector<string> getGray(int n) {
        // write code here
        int pown = pow(2, n);
        vector<string> gray;
        for(int i = 0; i < pown; i++){
            int graynum = i ^ (i/2);
            string graystr = getbinarystr(graynum,n);
            gray.push_back(graystr);
        }
        return gray;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

