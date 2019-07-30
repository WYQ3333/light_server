/*
 *给定一个二叉树，它的每个结点都存放着一个整数值。

 找出路径和等于给定数值的路径总数。

 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

 解决思路是：回溯法,每走一步，就判断data中的和是否为sum，如果是，将count++;否则再走左子树，在走右子树，之后将这个值pop掉,递归到上一层

 */
#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
class Solution{
public:
    int count;
    void every_sum(TreeNode* root, int sum, vector<int>& data, int& count){
        if(root == nullptr){
            return;
        }
        int num = 0;
        data.push_back(root->val);
        for(int i = data.size()-1; i >= 0; --i){
            num += data[i];
            if(num == sum){
                count++;
            }
        }
        every_sum(root->left, sum, data, count);
        every_sum(root->right, sum, data, count);
        data.pop_back();
    }
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr)
            return 0;
        vector<int> data;
        every_sum(root, sum, data, count);
        return count;
    }
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

