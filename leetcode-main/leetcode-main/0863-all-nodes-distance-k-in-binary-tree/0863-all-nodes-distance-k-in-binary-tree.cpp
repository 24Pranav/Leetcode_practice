/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markparents(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &map)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* front=q.front();
            q.pop();
            if(front->left)
            {
                map[front->left]=front;
                q.push(front->left);
            }
            if(front->right)
            {
                map[front->right]=front;
                q.push(front->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        markparents(root,parent_track);
        unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        queue<TreeNode*> q;
        q.push(target);
        int curr=0;
        while(!q.empty())
        {
            int size=q.size();
            if(curr==k)
                break;
            curr++;
            for(int i=0;i<size;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                //left
                if(front->left && !visited[front->left])
                {
                    q.push(front->left);
                    visited[front->left]=true;
                }
                //right
                if(front->right && !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right]=true;
                }
                //upwards to parent
                if(parent_track[front] && !visited[parent_track[front]])
                {
                    q.push(parent_track[front]);
                    visited[parent_track[front]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};