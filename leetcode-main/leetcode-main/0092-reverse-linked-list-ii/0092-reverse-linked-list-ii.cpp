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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* p1=head;
        ListNode* p2=head;
        
        int n=left-1;
        while(n--)
            p1=p1->next;
        n=right;
        while(n--)
            p2=p2->next;
        
        
        ListNode* p3=p1;
        ListNode* p4=p2;
        
        vector<int> temp;
        
        while(p1!=p2)
        {
            temp.push_back(p1->val);
            p1=p1->next;
        }
        
        reverse(temp.begin(),temp.end());
        
        int ind=0;
        while(p3!=p4)
        {
            p3->val=temp[ind++];
            p3=p3->next;
        }
        
        return head;
        
    }
};