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
        if(left == right) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        left -= 1;
        while(left--){
            prev = curr;
            curr = curr->next;
            right-=1;
        }
        ListNode* rcurr = curr;
        ListNode* found = prev;
        ListNode* nxt = NULL;
        while(right--){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        rcurr->next = curr;
        if(found == NULL) return prev;
        found->next = prev;
        return head;
    }
};
