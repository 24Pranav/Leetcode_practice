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
    int ans=0;
    int i=0;
    int getDecimalValue(ListNode* head) {
        //Recursive Approach
        // if(head==NULL) return 0; // base case
        // ans=getDecimalValue(head->next); // recursion call
        // int p=pow(2,i++);
        // if(head->val)
        // ans+=p;
        // return ans;
        
        //Iterative Approach
        ListNode* temp=head;
        while(temp!=NULL)
        {
            ans*=2;
            ans+=temp->val;
            temp=temp->next;
        }
        return ans;
    }
};