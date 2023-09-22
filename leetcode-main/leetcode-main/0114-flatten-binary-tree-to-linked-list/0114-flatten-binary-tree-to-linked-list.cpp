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
    //Right Left Root
    TreeNode* prev=NULL;
    void fun(TreeNode* root)
    {
        if(root==NULL)
            return;
        fun(root->right);
        fun(root->left);
        root->left=NULL;
        root->right=prev;
        prev=root;
        
    }
    void flatten(TreeNode* root) {
        fun(root);
    }
};