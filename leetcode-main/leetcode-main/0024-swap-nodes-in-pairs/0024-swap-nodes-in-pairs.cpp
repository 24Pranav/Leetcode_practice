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
    ListNode* swapPairs(ListNode* head) {
        // ListNode* temp=head;
        // if(head==NULL || head->next==NULL)
        //     return head;
        // int size=0;
        // ListNode* s=head;
        // while(s)
        // {
        //     size++;
        //     s=s->next;
        // }
        // bool flag=false;
        // if(size%2!=0)
        // flag=true;
        // while(temp && temp->next && temp->next->next)
        // {
        //     int tval=temp->val;
        //     temp->val=temp->next->val;
        //     temp->next->val=tval;
        //     temp=temp->next->next;
        // }
        // if(!flag){
        // cout<<temp->val;
        // int tval=temp->val;
        // temp->val=temp->next->val;
        // temp->next->val=tval;
        // }
        // return head;
        
        //recursive sol
        
        if(head==NULL || head->next==NULL)
            return head;
        
        int tmp=head->val;
        head->val=head->next->val;
        head->next->val=tmp;
        swapPairs(head->next->next);
        return head;
    }
};