#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getNext(string T)
{
    vector<int> next(T.size(), 0);            // next矩阵，含义参考王红梅版《数据结构》p84。
    next[0] = -1;                            // next矩阵的第0位为-1
    int k = 0;                            // k值
    for (int j = 2; j < T.size(); ++j)        // 从字符串T的第2个字符开始，计算每个字符的next值
    {
        while (k > 0 && T[j - 1] != T[k])    
            k = next[k];
        if (T[j - 1] == T[k])
            k++;
        next[j] = k;
    }
    return next;                            // 返回next矩阵
}

int KMP(string S, string T)
{
    vector<int> next = getNext(T);
    int i = 0, j = 0;
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
        if (j == -1)
        {
            ++i;
            ++j;
        }
    }
    if (T[j] == '\0')
        return i - j;
    else
        return -1;
}

int main()
{
    string S;
    cin >> S;
    string T;
    cin >> T;
    int num = KMP(S, T);
    cout << num << endl;
    return 0;
}

