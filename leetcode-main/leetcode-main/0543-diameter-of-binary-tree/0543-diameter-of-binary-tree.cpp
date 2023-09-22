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
    int maxi=0;
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int ans1=height(root->left);
        int ans2=height(root->right);
        maxi=max(maxi,ans1+ans2);
        return 1+max(ans1,ans2);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return maxi;
    }
};