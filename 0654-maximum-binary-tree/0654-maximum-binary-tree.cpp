/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0)return NULL;
        int maxIndex = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[maxIndex]<nums[i]){
                maxIndex = i;
            }
        }
        TreeNode* root = new TreeNode(nums[maxIndex]);
        vector<int> leftTree(nums.begin(),nums.begin()+maxIndex);
        vector<int> rightTree(nums.begin()+maxIndex+1,nums.end());
        root->left = constructMaximumBinaryTree(leftTree);
        root->right = constructMaximumBinaryTree(rightTree);
        return root;
    }
};