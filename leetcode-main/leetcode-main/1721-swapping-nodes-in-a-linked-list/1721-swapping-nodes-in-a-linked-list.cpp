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
    int size(ListNode* head)
    {
        ListNode* temp=head;
        int s=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            s++;
        }
        return s;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int n=k-1;
        ListNode* temp=head;
        ListNode* temp1=head;
        while(n--)
        {
            temp=temp->next;
        }
        n=size(head)-k;
        while(n--)
        {
            temp1=temp1->next;
        }
        int t=temp1->val;
        temp1->val=temp->val;
        temp->val=t;
        return head;
    }
};