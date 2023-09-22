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
//     map<int,int> sum,sum_parent;
//     void dfs1(TreeNode * root,int d) //Sum DFS
//     {
//         if(root==NULL)
//             return;
//         sum[d]+=root->val;
//         dfs1(root->left,d+1);
//         dfs1(root->right,d+1);
        
//     }
//     int cnt=0;
//     void dfs2(TreeNode* root,int parent_ind) //Parent Sum DFS
//     {
//         int cur_ind=cnt++;
//         if(root==NULL)
//             return;
//         sum_parent[parent_ind]+=root->val;
//         dfs2(root->left,cur_ind);
//         dfs2(root->right,cur_ind);
//     }
//     int cnt1=0;
//     void dfs3(TreeNode* root,int parent_ind,int d)//replace calculated value
//     {
//         int cur_ind=cnt1++;
//         if(root==NULL)
//             return;
//         int calc=sum[d]-sum_parent[parent_ind];
//         root->val=(calc<0)?0:calc;
//         dfs3(root->left,cur_ind,d+1);
//         dfs3(root->right,cur_ind,d+1);
//     }
//     TreeNode* replaceValueInTree(TreeNode* root) {
//         if(root==NULL)
//             return NULL;
//         dfs1(root,0);
//         dfs2(root,0);
//         dfs3(root,0,0);
//         //debug
//         // for(auto &x:sum_parent)
//         //     cout<<"index "<<x.first<<" sum "<<x.second<<"\n";
//         // cout<<endl;
//         return root;
//     }
    
    
    //Alternate Solution
    
        TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL)
            return NULL;
            
            map<TreeNode*,int> sumofchildren;
            queue<TreeNode*> q;
            q.push(root);
            //BFS
            //Sum of children of a parent and level sum
            int level=0;
            map<int,int> llsum;
            while(!q.empty())
            {
                int n=q.size();
                int lsum=0;
                for(int i=0;i<n;i++)
                {
                    auto it=q.front();        
                    q.pop();
                    int sum=0;
                    lsum+=it->val;
                    if(it->left){
                        sum+=it->left->val;
                        q.push(it->left);
                    }
                    if(it->right){
                        sum+=it->right->val;
                        q.push(it->right);
                    }
                    sumofchildren[it]=sum;
                }
                llsum[level++]=lsum;
            }
            
            //BFS for calculating val
            q.push(root);
            level=1; //skip root calc
            root->val=0; //set root val to 0
            while(!q.empty())
            {
                int n=q.size();
                for(int i=0;i<n;i++)
                {
                    auto it=q.front();
                    q.pop();
                    if(it->left)
                    {
                        q.push(it->left);
                        it->left->val=llsum[level]-sumofchildren[it];
                        // cout<<llsum[level]<<" "<<sumofchildren[it]<<endl;
                    }
                    if(it->right)
                    {
                        q.push(it->right);
                        it->right->val=llsum[level]-sumofchildren[it];
                        // cout<<llsum[level]<<" "<<sumofchildren[it]<<endl;

                    }
                }
                level++;
                
            }            
//             for(auto &x:sumofchildren)
//                 cout<<x.first->val<<" "<<x.second<<endl;
            
            return root;
    }
};