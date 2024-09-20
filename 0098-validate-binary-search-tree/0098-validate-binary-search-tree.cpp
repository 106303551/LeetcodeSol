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
    bool traversal(TreeNode* root,TreeNode* min,TreeNode* max){
        if(!root)return true;
        
        if((min && min->val>=root->val) || (max && max->val<=root->val))return false;

        return traversal(root->left,min,root) && traversal(root->right,root,max);
    }
    bool isValidBST(TreeNode* root) {
        return traversal(root,nullptr,nullptr);
    }
};
// class Solution {
// public:
//     long long maxVal = LONG_MIN; // 因为后台测试数据中有int最小值
//     bool isValidBST(TreeNode* root) {
//         if (root == NULL) return true;

//         bool left = isValidBST(root->left);
//         // 中序遍历，验证遍历的元素是不是从小到大
//         if (maxVal < root->val) maxVal = root->val;
//         else return false;
//         bool right = isValidBST(root->right);

//         return left && right;
//     }
// };