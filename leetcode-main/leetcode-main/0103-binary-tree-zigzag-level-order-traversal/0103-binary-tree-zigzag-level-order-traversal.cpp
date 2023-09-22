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
    vector<vector<int>> ans;
    vector<int> temp;
    queue<TreeNode*> q;
    bool flag=false;
    void fun(TreeNode* root)
    {
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
            TreeNode* front=q.front();
            q.pop();
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);   
            temp.push_back(front->val);
            }
            if(flag)
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            flag=!flag;
            temp.clear();
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//            if (root == NULL) {
//         return vector<vector<int> > ();
//     }
//     vector<vector<int> > result;

//     queue<TreeNode*> nodesQueue;
//     nodesQueue.push(root);
//     bool leftToRight = true;

//     while ( !nodesQueue.empty()) {
//         int size = nodesQueue.size();
//         vector<int> row(size);
//         for (int i = 0; i < size; i++) {
//             TreeNode* node = nodesQueue.front();
//             nodesQueue.pop();

//             // find position to fill node's value
//             int index = (leftToRight) ? i : (size - 1 - i);

//             row[index] = node->val;
//             if (node->left) {
//                 nodesQueue.push(node->left);
//             }
//             if (node->right) {
//                 nodesQueue.push(node->right);
//             }
//         }
//         // after this level
//         leftToRight = !leftToRight;
//         result.push_back(row);
//     }
//     return result;
        if(root==NULL)
        return ans;
        fun(root);
        return ans;
    }
};