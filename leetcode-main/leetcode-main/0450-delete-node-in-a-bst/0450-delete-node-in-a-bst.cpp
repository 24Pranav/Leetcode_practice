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
    TreeNode* leftr(TreeNode* root)
    {
        if(root->right==NULL)
            return root;
        return leftr(root->right);
    }
    TreeNode* fun(TreeNode* root)
    {
        if(root->left==NULL)
            return root->right;
        if(root->right==NULL)
            return root->left;
        TreeNode* rightchild=root->right;
        TreeNode* leftright=leftr(root->left);
        leftright->right=rightchild;
        return root->left;
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return root;
        if(root->val==key)
        {
            return fun(root);
        }
        TreeNode* root1=root;
        while(root)
        {
            if(key < root->val)
            {
                if(root->left!=NULL && root->left->val==key)
                {
                    root->left=fun(root->left);
                    break;
                }
                else
                    root=root->left;
            }
            else
            {
                if(root->right!=NULL && root->right->val==key)
                {
                    root->right=fun(root->right);
                    break;
                }
                else
                    root=root->right;
            }
        }
        return root1;
    }
};