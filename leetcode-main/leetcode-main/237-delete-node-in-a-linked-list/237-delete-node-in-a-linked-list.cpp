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
    void deleteNode(ListNode* node) {
        // *node=*(node->next); Trick changing the address
        node->val=node->next->val; // Swapping the values with next element
        node->next=node->next->next;   
    }
};