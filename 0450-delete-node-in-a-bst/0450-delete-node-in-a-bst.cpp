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
    TreeNode* combinedTwoTree(TreeNode* root1,TreeNode* root2){
        if(!root1)return root2;
        if(!root2)return root1;
        TreeNode* newroot;
        //抓小的當root
        if(root1->val<root2->val){
            newroot = root1;
            root1 = root1->right;
        }else{
            newroot = root2;
            root2 - root2->right;
        }
        newroot->right = combinedTwoTree(root1,root2);
        return newroot;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //不存在node
        if(!root) return nullptr;

        TreeNode* cur = root;
        TreeNode* pre = NULL;

        //找到node
        while(cur && cur->val != key){
            pre = cur;
            if(cur->val<key){
                cur = cur->right;
            }else{
                cur = cur->left;
            }
        }

        //1.要刪除的節點不存在
        if(!cur){
            return root;
        }
        
        //2.刪除node
        //2.1.root
        if(!pre){
            root = combinedTwoTree(cur->left,cur->right);
        }//2.2.leftNode
        else if(pre->left == cur){
            pre->left = combinedTwoTree(cur->left,cur->right);
        }//2.3.rightNode
        else{
            pre->right = combinedTwoTree(cur->left,cur->right);
        }
        

        return root;
    }
};