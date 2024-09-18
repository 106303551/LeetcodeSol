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
    void findPath(TreeNode* root ,int targetSum,vector<int> path,vector<vector<int>>& result){
        path.push_back(root->val);
        if(!root->left &&　!root->right){
            int sum = 0;
            for(int e:path){
                sum+=e;
            }
            if(sum == targetSum){
                result.push_back(path);
            }
        }
        if(root->left)findPath(root->left,targetSum,path,result);
        if(root->right)findPath(root->right,targetSum,path,result);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        if(root) findPath(root,targetSum,path,result);
        return result;

    }
};