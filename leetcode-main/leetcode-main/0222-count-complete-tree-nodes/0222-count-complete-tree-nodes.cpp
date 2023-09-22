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
    int height(TreeNode* root,int left)
    {
        int cnt=0;
        while(root)
        {
            cnt++;
            if(left)
            root=root->left;
            else
                root=root->right;
        }
        return cnt;
    }
    int fun(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lh=height(root,1);
        int rh=height(root,0);
        //If in a tree all nodes are filled then no of nodes equals to 2^h-1 where h is height
        if(lh==rh)
            return (1<<lh) -1;
        else
            return 1+fun(root->left)+fun(root->right);
    }
    int countNodes(TreeNode* root) {
        return fun(root);
    }
};