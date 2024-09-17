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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> result;
        if(root!=NULL)que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> subresult;
            for(int i = 0;i<size;i++){
                TreeNode* cur = que.front();
                subresult.push_back(cur->val);
                que.pop();
                if(cur->left!=NULL)que.push(cur->left);
                if(cur->right!=NULL)que.push(cur->right);
            }
            result.push_back(subresult);
        }
        return result;
    }
};