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
    using ll=long long;
    map<ll,ll> levelsum;
    void dfs(TreeNode* root,int level)
    {
        if(root==NULL)
            return;
        dfs(root->left,level+1);
        levelsum[level]+=root->val;
        dfs(root->right,level+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        dfs(root,0);
        priority_queue<ll> pq;
        ll ans,maxi=INT_MIN;
        for(auto &[a,b]:levelsum){
            // cout<<b<<" ";
            pq.push(b);
        }
        if(k>pq.size())
            return -1;
        k-=1;
        while(k--)
            pq.pop();
        return pq.top();
    }
};