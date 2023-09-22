/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void print(vector<int> &vec)
    {
        for(auto &x:vec)
            cout<<x<<" ";
        cout<<endl;
    }
    ListNode* partition(ListNode* head, int x) {
        ListNode* tmp=head;
        vector<int> vec;
        vector<int> vis;
        while(tmp)
        {
            if(tmp->val<x){
            vec.push_back(tmp->val);
            }
            else
                vis.push_back(tmp->val);
            tmp=tmp->next;

        }
        tmp=head;
        int i1=0;
        int i2=0;
        while(tmp)
        {
            if(i1<vec.size())
            tmp->val=vec[i1++];
            else
            tmp->val=vis[i2++];
            tmp=tmp->next;
        }
        // print(vec);
        // print(vis);
        return head;
    }
};