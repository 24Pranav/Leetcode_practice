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
    void fun(TreeNode* root,int d,int dir)
    {
        if(root==NULL)
            return;
        maxi=max(maxi,d);
        if(dir==0){ //left
        fun(root->left,d+1,1);
        return fun(root->right,1,0);
        }
        if(dir==1) //right
        {
        fun(root->right,d+1,0);
        fun(root->left,1,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        //dir 0 (left)
        //dir 1 (right)
        fun(root,0,0);
        fun(root,0,1);
        return maxi;
    }
};