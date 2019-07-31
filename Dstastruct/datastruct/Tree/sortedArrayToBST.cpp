#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return constructBST(nums, 0, nums.size()-1);
    }
private:
    TreeNode *constructBST(vector<int> &nums, int lf, int rt) 
    {
        if (lf > rt) return nullptr;
        int mid = (lf+rt)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = constructBST(nums, lf, mid-1);
        root->right = constructBST(nums, mid+1, rt);
        return root;
    }
};
int main()
{
    return 0;
}

