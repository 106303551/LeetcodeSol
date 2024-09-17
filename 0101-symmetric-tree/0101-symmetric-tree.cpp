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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        que.push(left);
        que.push(right);
        while(!que.empty()){
            left = que.front();que.pop();
            right = que.front();que.pop();
            if(!left &&!right){
                continue;
            }
            if(!left || !right || (left->val!=right->val)){
                return false;
            }
            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};