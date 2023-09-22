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
        int count=0;
        while(head)
        {
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int n=size(head);
        k=k%n;
        if(k==0)
            return head;
        n=n-k-1;
        ListNode* temp=head;
        while(n--)
        {
            temp=temp->next;
        }
        ListNode* p1=temp;
        temp=temp->next;
        p1->next=NULL;
        
        ListNode* newhead=temp;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head;
        return newhead;
    }
};