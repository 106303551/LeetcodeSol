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
    void InOrder(TreeNode* root,vector<int>& result){
        if(!root->left && !root->right){
            result.push_back(root->val);
            return;
        }
        if(root->left)InOrder(root->left,result);
        result.push_back(root->val);
        if(root->right)InOrder(root->right,result);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        vector<int> ans;
        int count = 1;
        int maxcount = 1;
        InOrder(root,result);
        if(result.size()==1) return result;

        for(int i = 1;i<result.size();i++){
            if(result[i]==result[i-1]){
                count++;
            }else{
                if(maxcount == count){
                    ans.push_back(result[i-1]);
                }else if (maxcount<count){
                    ans.clear();
                    maxcount = count;
                    ans.push_back(result[i-1]);
                }
                count = 1;
            }
        }
        //考慮最後一個的情況
        if(maxcount<count){
            ans.clear();
            ans.push_back(result[result.size()-1]);
        }
        if(count == maxcount){
            ans.push_back(result[result.size()-1]);
        }

        return ans;
    }
};