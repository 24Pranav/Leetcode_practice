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
    TreeNode* prev=NULL;
    void insert(TreeNode* root, TreeNode* node, int val)
    {
        if(root==NULL)
        {
            if(val > prev->val)
            prev->right=node;
        else
            prev->left=node;
            return;
        }
        prev=root;
        if(val>root->val)
            insert(root->right,node,val);
        else
            insert(root->left,node,val);
        
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node= new TreeNode(val);
        if(root==NULL)
            return node;
        insert(root,node,val);
        return root;
    }
};