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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* node=new ListNode(-1,head);
        ListNode* prev=node;
        ListNode* temp=head;
        if(head==NULL) return head;
        while(temp)
        {
            if(temp->val!=val)
            {
                node->next=temp;
                node=node->next;
                // node->next=NULL;
            }
            temp=temp->next;
        }
        node->next=NULL;
        return prev->next;
    }
};