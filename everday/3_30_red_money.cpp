#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Gift {
public:
 int getValue(vector<int> gifts, int n) {
     // write code here
     sort(gifts.begin(), gifts.end());
     if(n == 1){
         return gifts[0];
     }
     if(n == 2 && gifts[0]==gifts[1]){
         return gifts[0];
     }
     if(n == 2 && gifts[0]!=gifts[1]){
         return 0;
     }
     int result = gifts[0];
     int count = 0;
     int index = 0;
     for(int i = 0; i < n; ++i){
         if(gifts[i] == result){
             count++;
         }
         else{
             if(count >= (n/2+1)){
                 index = i-1;
             }
             count = 1;
             result = gifts[i];
         }
     }
     int temp = 0;
     if(index != 0){
         temp = gifts[index];
     }
     return temp;
 }
};
/* class Gift { */
/* public: */
/*     int getValue(vector<int> gifts, int n) { */
/*         // write code here */
/*         sort(gifts.begin(), gifts.end()); */
/*         int result = gifts[0]; */
/*         int count = 0; */
/*         int index = 0; */
/*         for(int i = 0; i < n; ++i){ */
/*             if(gifts[i] == result){ */
/*                 count++; */
/*             } */
/*             else{ */
/*                 if(count >= (n/2+1)){ */
/*                     index = i-1; */
/*                 } */
/*                 count = 1; */
/*                 result = gifts[i]; */
/*             } */
/*         } */
/*         return gifts[index]; */
/*     } */
/* }; */
int main()
{
    Gift g;
    vector<int> array{1, 2, 3, 2, 2};
    int result = 0;
    result = g.getValue(array, array.size());
    cout << result << endl;
    return 0;
}

