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
    int maxcount=0;
    unordered_map<int,int> mp;
    int subtreesum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int l=subtreesum(root->left);
        int r=subtreesum(root->right);
        int cursum=l+r+root->val;
        mp[cursum]++;
        maxcount=max(maxcount,mp[cursum]);
        return cursum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        subtreesum(root);
        for(auto &x:mp)
        {
            if(x.second==maxcount)
                ans.push_back(x.first);
        }
        return ans;
    }
};