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
    void fun(TreeNode* root,vector<string>& ans,string curr)
    {
        if(root==NULL)
            return;
        if(root->left || root->right)
            curr+=(to_string(root->val)+"->");
        else
        {
            curr+=to_string(root->val);
            ans.push_back(curr);
        }
        fun(root->left,ans,curr);
        fun(root->right,ans,curr);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string curr="";
        fun(root,ans,curr);
        return ans;
    }
};