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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ptr1=list1;
        ListNode* ptr2=list2;
        ListNode* newhead= new ListNode(0,NULL);
        ListNode* temp=newhead;
        while(ptr1 && ptr2)
        {
            if(ptr1->val < ptr2->val)
            {
                temp->next=ptr1;
                ptr1=ptr1->next;
            }
            else
            {
                temp->next=ptr2;
                ptr2=ptr2->next;
            }
            temp=temp->next;
        }
        while(ptr1)
        {
            temp->next=ptr1;
            ptr1=ptr1->next;
            temp=temp->next;
        }
        while(ptr2)
        {
            temp->next=ptr2;
            ptr2=ptr2->next;
            temp=temp->next;
        }
        return newhead->next;
    }
};