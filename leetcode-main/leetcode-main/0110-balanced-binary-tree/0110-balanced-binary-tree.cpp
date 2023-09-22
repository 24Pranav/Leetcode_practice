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
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int ans1=height(root->left);
        int ans2=height(root->right);
        if(ans1==-1 || ans2==-1)
            return -1;
        if(abs(ans1-ans2)>1)
            return -1;
        return 1+max(ans1,ans2);
    }
    // bool fun(TreeNode* root)
    // {
    //     if(root==NULL)
    //         return true;
    //     int lh=height(root->left);
    //     int rh=height(root->right);
    //     if(abs(lh-rh)>1)
    //         return false;
    //     bool left=fun(root->left);
    //     bool right=fun(root->right);
    //     if(left && right) return true;
    //     else
    //         return true;
    // }
    bool isBalanced(TreeNode* root) {
       // return fun(root);
        return height(root)!=-1;
    }
};