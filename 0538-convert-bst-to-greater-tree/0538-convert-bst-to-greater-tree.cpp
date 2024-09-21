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
    TreeNode* convertBST(TreeNode* root) {
        if(!root)return root;
        stack<TreeNode*> stk;
        int count = 0;
        TreeNode* cur = root;
        while(cur!=NULL || !stk.empty()){
            if(cur!=NULL){
                stk.push(cur);
                cur = cur->right;
            }else{
                cur = stk.top();
                stk.pop();
                int tmp = cur->val;
                cur->val+=count;
                count+=tmp;
                cur = cur->left;
            }
        }
        return root;
    }
};