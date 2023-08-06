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
        
        //copying the value of node next the node which is to be deleted
        node->val=node->next->val;
        //value of node
        node->next=node->next->next;
        
        
    }
};