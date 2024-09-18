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
    int calSum(TreeNode*root,int count,int targetSum){
        int leftsum,rightsum;
        int res = count+root->val;
        if(!root->left && !root->right)return res;
        if(root->left){
            leftsum =calSum(root->left,res,targetSum);
            if(leftsum == targetSum)return targetSum;
        }
        if(root->right){
            rightsum = calSum(root->right,res,targetSum);
            if(rightsum==targetSum)return targetSum;
        }
        return targetSum-1;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root && calSum(root,0,targetSum) == targetSum)return true;
        return false;
    }
};