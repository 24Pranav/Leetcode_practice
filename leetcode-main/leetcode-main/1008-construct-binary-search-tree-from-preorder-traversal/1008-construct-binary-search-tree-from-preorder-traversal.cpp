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
    TreeNode* fun(vector<int> &arr,int &i,int upbound)
    {
     if(arr.size()==i || arr[i]>upbound)
         return NULL;
        TreeNode* root=new TreeNode(arr[i++]);
        root->left=fun(arr,i,root->val);
        root->right=fun(arr,i,upbound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        if(preorder.size()==0)
            return NULL;
        return fun(preorder,i,INT_MAX);
    }
};