/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int high,low;
        high = max(p->val,q->val);
        low = min(p->val,q->val);

        if(root->val==high || root->val==low)return root;

        if(root->val>low && root->val<high){
            return root;
        }
        else if(root->val<low &&root->val<high){
            return lowestCommonAncestor(root->right,p,q);
        }
        else{
            return lowestCommonAncestor(root->left,p,q);
        }
    }
};