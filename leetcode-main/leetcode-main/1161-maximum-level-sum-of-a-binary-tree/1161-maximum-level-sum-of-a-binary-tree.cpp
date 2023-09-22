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
    map<int,int> levelsum;
    void dfs(TreeNode* root,int level)
    {
        if(root==NULL)
            return;
        dfs(root->left,level+1);
        levelsum[level]+=root->val;
        dfs(root->right,level+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root,0);
        int ans,maxi=INT_MIN;
        for(auto &[a,b]:levelsum){
         if(b>maxi){
             maxi=b;
             ans=a+1;}
        }
        return ans;
    }
};