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
    void reverse(ListNode* start, ListNode* end)
    {
        ListNode *prev=NULL, *curr=start , *nxt=start->next;
        while(prev!=end) // curr!=NULL because after end there are more elements (IMP)
        {
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(nxt)
                nxt=nxt->next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==1) return head;
        ListNode* start=head;
        ListNode* end=head;
        int pos=k-1;
        while(pos--)
        {
            end=end->next;
            if(end==NULL) return head;
        }
        ListNode* nexthead=reverseKGroup(end->next,k);
        reverse(start,end);
        head->next=nexthead; //or start->next
        return end;
    }
};