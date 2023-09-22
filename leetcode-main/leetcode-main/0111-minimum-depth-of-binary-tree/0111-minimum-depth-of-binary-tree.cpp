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
    int minDepth(TreeNode* root) {
                 if (root == NULL) {
            return 0;
        }
        int left_depth = minDepth(root->left)+1;
        int right_depth = minDepth(root->right)+1;
        if(root->left==NULL)
            return right_depth;
        if(root->right==NULL)
            return left_depth;
        return min(left_depth, right_depth);
    }
};