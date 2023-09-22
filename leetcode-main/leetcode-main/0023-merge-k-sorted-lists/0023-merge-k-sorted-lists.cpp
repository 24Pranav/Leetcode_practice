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
    class cmp{
    public:
    bool operator() (ListNode* a , ListNode* b)
    {
        return a->val > b->val;
    }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& v) {
        priority_queue<ListNode*, vector<ListNode*>,cmp> q;
        ListNode* dummy=new ListNode(-1,NULL);
        ListNode* tail=dummy;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=NULL)
            {
                q.push(v[i]);
            }
        }
        while(q.size())
        {
            ListNode* temp=q.top();
            tail->next=temp;
            tail=temp;
            q.pop();
            if(temp->next!=NULL)
            q.push(temp->next);
        }
        return dummy->next;
    }
};