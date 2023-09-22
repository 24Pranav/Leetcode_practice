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
class Solution {
public:
    vector<vector<pair<ll,ll>>> ans;
    vector<pair<ll,ll>> temp;
    queue<pair<TreeNode*,ll>> q;
    ll maxi=0;
    void fun(TreeNode* root)
    {
        q.push({root,0});
        while(!q.empty())
        {
            int n=q.size();
            ll minil=q.front().second;
            for(int i=0;i<n;i++)
            {
            pair<TreeNode*,ll> front=q.front();
            ll curr=front.second-minil;
            q.pop();
            if(front.first->left)
                q.push({front.first->left,2*(curr)+1});
            if(front.first->right)
                q.push({front.first->right,2*(curr)+2});   
            temp.push_back({front.first->val,front.second});
            }
            ans.push_back(temp);
            ll n_1=ans.size();
            ll n1=ans[n_1-1].size();
            maxi=max(maxi,abs(ans[n_1-1][0].second-ans[n_1-1][n1-1].second)+1);
            temp.clear();
        }
    }
    void print(vector<vector<pair<ll,ll>>> &ans)
    {
        for(auto x:ans)
        {
            for(auto j:x)
                cout<<j.second<<" ";
            cout<<endl;
        }
    }
    int levelOrder(TreeNode* root) {
        if(root==NULL)
            return 0;
        fun(root);
        print(ans);
        return maxi;
    }
    int widthOfBinaryTree(TreeNode* root) {
        // return levelOrder(root);
        if(root==NULL)
        return 0;
        queue<pair<TreeNode*,ll>> q;
        q.push({root,0});
        ll maxi=0;
        //BFS
        while(!q.empty())
        {
            ll n=q.size();
            ll first=q.front().second;
            ll last=q.back().second;
            maxi=max(maxi,(last-first+1));
            ll mini=q.front().second;
            while(n--)
            {
                auto it=q.front();
                q.pop();
                TreeNode* curr=it.first;
                ll d=it.second-mini;
                if(curr->left)
                {
                    q.push({curr->left,(2*d)+1});
                }
                if(curr->right)
                {
                    q.push({curr->right,(2*d)+2});
                }
                
            }
        }
        return maxi;
    }
};