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
    int calleft(TreeNode*root){
        if(!root)return 0;
        if(!root->left && !root->right){
            return root->val;
        }else{
            return calleft(root->left)+calright(root->right);
        }
    }
    int calright(TreeNode* root){
        if(!root)return 0;
        return calleft(root->left)+calright(root->right);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return calleft(root->left)+calright(root->right);
    }
};