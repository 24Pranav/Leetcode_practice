/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        Node* newhead= new Node(head->val);
        unordered_map<Node*,Node*> mp;
        Node* tmp=head;
        Node* tmp1=newhead;
        tmp=tmp->next;
        mp[head]=newhead;
        while(tmp)
        {
            Node* node=new Node(tmp->val);
            tmp1->next=node;
            tmp1=tmp1->next;
            mp[tmp]=tmp1;
            tmp=tmp->next;
        }
        // for(auto &[a,b]:mp){
        //     cout<<a<<" ";
        //     if(b)
        //         cout<<b->val<<endl;
        //     }
        tmp=head;
        tmp1=newhead;
        while(tmp)
        {
            tmp1->random=mp[tmp->random];
            tmp1=tmp1->next;
            tmp=tmp->next;
        }
        return newhead;
    }
};