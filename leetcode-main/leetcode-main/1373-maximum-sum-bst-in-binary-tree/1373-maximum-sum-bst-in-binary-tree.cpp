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
class NodeValue {
public: 
    int minNode, maxNode, maxSum;
    NodeValue(int minNode, int maxNode, int maxSum)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};
class Solution {
public:
    NodeValue fun(TreeNode* root)
    {
        if(!root) return NodeValue(INT_MAX, INT_MIN, 0);
        
        auto left = fun(root->left);
        auto right = fun(root->right);
        //BST
        if(left.maxNode < root->val && root->val < right.minNode)
        {
            sum = max(sum, root->val + left.maxSum + right.maxSum);
            
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), root->val + left.maxSum + right.maxSum);
            
        }
        
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum));   
    }
    int sum=0;
    int maxSumBST(TreeNode* root) {
        fun(root);
        return sum>0 ? sum : 0;
    }
};