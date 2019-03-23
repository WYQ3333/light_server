#include <iostream>
#include<map>
#include<string>
using namespace std;

void TestMap()
{
    // key和value的类型都给成字符串
     map<string, string> m1;
     // C++11 的类表初始化
     map<string, string> m2{ { "apple", "苹果"  },
     { "banan", "香蕉"  },
     { "orange", "橘子"  },
     { "peach", "桃子"  },
     { "waterme", "水蜜桃"  } };
     cout << m2["apple"] << endl;
     cout << m2["waterme"] << endl;
     map<string, string> m3(m2);
}

int main()
{
    map<string,string> m{{"apple", "苹果"}
        ,{"banan", "香蕉"}, {"orgin", "橘子"}, {"peach", "桃子"
        }};
    cout << m["banan"] << endl;
    for(auto e : m){
        cout << e.first << "--->";
        cout << e.second << std::endl;
    }
    return 0;
}

