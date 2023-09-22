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
    int fun(TreeNode* root,int &maxi)
    {
        if(root==NULL)
        return 0;
        int left=max(0,fun(root->left,maxi)); // To avoid negative sum
        int right=max(0,fun(root->right,maxi)); // To avoid negative sum
        maxi=max(maxi,root->val + (left+right)); // maxi=root->val + left+right
        return max(left+root->val,right+root->val); // max sum left part or right part
    }
// int solve(TreeNode* root,int &res)
//     {
//         if(root==NULL) return NULL;
//         int ls = solve(root->left,res);
//         int rs = solve(root->right,res);
//         int temp = max(max(ls,rs)+root->val,root->val);
//         int ans = max(temp,ls+rs+root->val);
//         res = max(res,ans);
//         return temp;
//     }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        // solve(root,res);
        // return res;
        fun(root,res);
        return res;
    }
};