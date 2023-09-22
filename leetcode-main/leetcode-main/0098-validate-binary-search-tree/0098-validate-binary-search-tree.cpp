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
#define ll long long
class Solution {
public:
    bool fun(TreeNode* root,ll left ,ll right)
    {
        if(root==NULL)
            return true;
        if(root->val>=right || root->val <= left)
            return false;
        bool lt=fun(root->left,left,root->val);
        bool rt=fun(root->right,root->val,right);
        return lt and rt;
    }
    bool isValidBST(TreeNode* root) {
        return fun(root,LLONG_MIN,LLONG_MAX);
    }
};