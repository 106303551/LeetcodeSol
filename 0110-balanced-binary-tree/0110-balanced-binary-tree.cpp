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
    int calDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftheight = calDepth(root->left);
        if(leftheight == -1) return -1;
        int rightheight = calDepth(root->right);
        if (rightheight==-1) return -1;

        return abs(leftheight-rightheight)>1 ? -1:1+max(leftheight,rightheight);
    }
    bool isBalanced(TreeNode* root) {
        return calDepth(root) ==-1 ? false:true;
    }
};