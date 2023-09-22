/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* node= new ListNode(0,head);
        ListNode* slow=node;
        ListNode* fast=node;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                fast=node;
                while(fast!=slow)
                {
                    fast=fast->next;
                    slow=slow->next;
                    if(slow==fast) return fast;
                }
            }
        }
        return NULL;
    }
};