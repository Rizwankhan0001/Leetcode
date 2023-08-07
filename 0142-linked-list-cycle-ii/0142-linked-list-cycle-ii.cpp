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
    ListNode *detectCycle(ListNode *head) {
        ListNode * fast=head;
        ListNode * slow =head;
        while(true){
            if (fast == NULL || fast->next==NULL || fast->next->next ==NULL){return NULL;}
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){break;
                          }
        }
        while(true){
            if(fast->next==slow){break;
                                }
            fast=fast->next;}
        if(slow==head){return head;
                      }
        else{ 
            while(slow !=head){
                slow=slow->next;
                head=head->next;}
            return head;
        }
    }
};