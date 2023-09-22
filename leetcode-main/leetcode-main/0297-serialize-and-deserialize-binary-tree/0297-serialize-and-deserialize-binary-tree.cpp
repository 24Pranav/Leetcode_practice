/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "";
        string str="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode *front=q.front();
                q.pop();
                if(front==NULL)
                    str+="#,";
                else
                    str+=to_string(front->val)+',';
                if(front!=NULL)
                {
                    q.push(front->left);
                    q.push(front->right);
                }
            }
        }
        cout<<str;
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)
            return NULL;
        stringstream sstream(data);
        string str;
        getline(sstream,str,',');
        TreeNode *root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {

            TreeNode* front=q.front();
            q.pop();
            //left
            getline(sstream,str,',');
            if(str=="#")
                front->left=NULL;
            else
            {
                TreeNode *lnode=new TreeNode(stoi(str));
                front->left=lnode;
                q.push(lnode);
            }
            //right
            getline(sstream,str,',');
            if(str=="#")
                front->right=NULL;
            else
            {
                TreeNode *rnode=new TreeNode(stoi(str));
                front->right=rnode;
                q.push(rnode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));