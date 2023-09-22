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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> v1;
        vector<int> v2;
        while(l1!=NULL)
        {
            v1.push_back(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL)
        {
            v2.push_back(l2->val);
            l2=l2->next;
        }
        int n1=v1.size();
        int n2=v2.size();
        int c=abs(n1-n2);
        while(v1.size()!=v2.size())
        {
            if(n1<n2)
                v1.insert(v1.begin(),0);
            else
                v2.insert(v2.begin(),0);
        }
        n1=v1.size();
        vector<int> ans(n1,0);
        int carry=0;
        for(int i=n1-1;i>=0;i--)
        {
            int c=v1[i]+v2[i]+carry;
            ans[i]=c%10;
            carry=c/10;
        }
        if(carry)
            ans.insert(ans.begin(),carry);
        // for(auto &x:ans)
        //     cout<<x<<" ";
        ListNode *h1=new ListNode(-1);
        ListNode *temp=h1;
        for(int i=0;i<ans.size();i++)
        {
            ListNode *node=new ListNode(ans[i]);
            h1->next=node;
            h1=h1->next;
        }
        return temp->next;
    }
};