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
    int calDepth(TreeNode* root , int depth){
        if(!root)return depth;
        depth++;
        int leftdepth=calDepth(root->left,depth);
        int rightdepth=calDepth(root->right,depth);
        return max(leftdepth,rightdepth);
    }
    int maxDepth(TreeNode* root) {
        int result = 0;

        result = calDepth(root,result);

        return result;
    }
};