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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==1) return new TreeNode(nums[0]);
        //高度平衡從中間切
        int splitIndex = nums.size()/2;
        TreeNode* root = new TreeNode(nums[splitIndex]);

        //定義左右樹
        //左樹:[start,splitIndex)
        //右樹:(splitIndex,end]
        vector<int> leftsub(nums.begin(),nums.begin()+splitIndex);
        root->left = sortedArrayToBST(leftsub);
        if(splitIndex+1<nums.size()){
            vector<int> rightsub(nums.begin()+splitIndex+1,nums.end());
            root->right = sortedArrayToBST(rightsub);
        }
        return root; 
    }
};