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
    int countNodes(TreeNode* root) {
        int count = 0;
        stack<TreeNode*> sk;
        if(root)sk.push(root);
        while(!sk.empty()){
            TreeNode* cur = sk.top();
            sk.pop();
            if(cur->left)sk.push(cur->left);
            if(cur->right)sk.push(cur->right);
            count++;
        }
        return count;
    }
};