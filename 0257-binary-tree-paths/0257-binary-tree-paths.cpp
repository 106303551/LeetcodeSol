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
    void findPath(TreeNode*root,string startPath,vector<string>& result){
        if(!root) return;
        string p = startPath+"->"+to_string(root->val);
        //遇到子點
        if(!root->right && !root->left){
            result.push_back(p);
        }
        findPath(root->left,p,result);
        findPath(root->right,p,result);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string p = to_string(root->val);
        if(!root->left && !root->right){
            result.push_back(p);
        }else{
            findPath(root->left,p,result);
            findPath(root->right,p,result);
        }
        return result;
    }
};