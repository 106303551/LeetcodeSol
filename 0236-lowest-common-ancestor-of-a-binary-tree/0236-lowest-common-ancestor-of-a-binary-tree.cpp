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
    // bool traversal(TreeNode*root,TreeNode* p ,TreeNode* q,TreeNode*& result){
    //     if(!root)return false;        
    //     bool flag1 = false, flag2 = false;
        
    //     if(root==p || root ==q){
    //         flag1 = true;
    //     }
    //     //左樹有node
    //     if(traversal(root->left,p,q,result)){
    //         if(!flag1){
    //             flag1 = true;
    //         }
    //         else{
    //             flag2 = true;
    //         }
    //     }
    //     //檢查右樹
    //     if(traversal(root->right,p,q,result)){
    //         if(!flag1){
    //             flag1 = true;
    //         }else{
    //             flag2 = true;
    //         }
    //     }

    //     if(result == NULL && flag1 && flag2){
    //         result = root;
    //     }
    //     return flag1 || flag2;
    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     //後序 左右中(向上查)
    //     TreeNode* result = NULL;
    //     traversal(root,p,q,result);
    //     return result;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //找到node就停止(if子點有另一點，此點必為ancestor)
        if(root == q|| root==p || root==NULL)return root;
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left&&right){
            return root;
        }
        if(!left){
            return right;
        }
        return left;
    }
};