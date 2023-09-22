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
    vector<int> arr;
    int i=0;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        arr.push_back(root->val);
        inorder(root->right);
        return;
    }
    void inorderfix(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorderfix(root->left);
        root->val=arr[i++];
        cout<<root->val<<" ";
        inorderfix(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(arr.begin(),arr.end());
        inorderfix(root);
    }
};