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
    // Using Inorder Traversal
    // vector<int> ans;
    // vector<int> temp;
    // queue<TreeNode*> q;
    // void fun(TreeNode* root)
    // {
    //     q.push(root);
    //     while(!q.empty())
    //     {
    //         int n=q.size();
    //         for(int i=0;i<n;i++)
    //         {
    //         TreeNode* front=q.front();
    //         q.pop();
    //         if(front->left)
    //             q.push(front->left);
    //         if(front->right)
    //             q.push(front->right);   
    //         temp.push_back(front->val);
    //         }
    //         ans.push_back(temp[temp.size()-1]);
    //         temp.clear();
    //     }
    // }
    // vector<int> rightSideView(TreeNode* root) {
    //     if(root==NULL)
    //     return ans;
    //     fun(root);
    //     return ans;
    // }
    
    //Alternate Soluttion
    void fun(TreeNode* root,int level,vector<int> &ans)
    {
        if(root==NULL)
            return;
        if(ans.size()==level)
            ans.push_back(root->val);
        fun(root->right,level+1,ans);
        fun(root->left,level+1,ans);
    }
        vector<int> rightSideView(TreeNode* root) {
            vector<int> ans;
        if(root==NULL)
        return ans;
        fun(root,0,ans);
        return ans;
    }
    
};