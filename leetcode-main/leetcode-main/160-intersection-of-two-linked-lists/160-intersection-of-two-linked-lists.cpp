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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0,m=0;
        ListNode* a=headA;
        ListNode* b=headB;
        while(a)
        {
            a=a->next;
            n++;
        }
        a=headA;
        while(b)
        {
            b=b->next;
            m++;
        }
        b=headB;
        int flag;
        int k=abs(n-m);
        if(n>m) flag=1; else flag=2;
        if(flag==1)
        {
            while(k--) a=a->next;
        }if(flag==2)
        {
            while(k--) b=b->next;
        }
        while(a || b)
        {
            if(a==b) return a;
            a=a->next;
            b=b->next;
        }
        return NULL;
    }
};