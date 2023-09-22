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
#define MAX(A,B) (A>B)?A:B
class Solution {
public:
    long long total;
    long long maxi=1;
    const int MOD=1e9+7;
    using ll=long long;
    void totsum(TreeNode* root)
    {
        if(root==NULL)
            return;
        if(root->left)
            totsum(root->left);
        if(root->right)
            totsum(root->right);
        total+=root->val;
    }
    ll subtreesum(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        ll l=subtreesum(root->left);
        ll r=subtreesum(root->right);
        ll curr_sum=(l+r+root->val);
        ll curr_pro=(curr_sum*(total-curr_sum));
        maxi=MAX(maxi,curr_pro);
        return curr_sum;
    }
    int maxProduct(TreeNode* root) {
        totsum(root);
        subtreesum(root);
        return (maxi%MOD);
    }
};