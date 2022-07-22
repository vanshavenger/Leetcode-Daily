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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;
        ListNode* h1 = NULL;
        ListNode* h2 = NULL;
        ListNode* t1 = NULL;
        ListNode* t2 = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            if(temp->val < x){
                if(h1 == NULL){
                    h1 = temp;
                    t1 = temp;
                }else{
                    t1 -> next = temp;
                    t1 = t1->next;
                }
            }else{
                if(h2 == NULL){
                    h2 = temp;
                    t2 = temp;
                }else{
                    t2->next = temp;
                    t2 = t2->next;
                    
                }
            }
            temp = temp->next;
        }
        if(h1 == NULL){
            t2 = t2 -> next;
            return h2;
        }
        if(h2 == NULL){
            t1 -> next = NULL;
            return h1;
        }
        t1 ->next = h2;
        t2 ->next = NULL;
        return h1;
        
    }
};
