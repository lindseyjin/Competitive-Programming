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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // two pointers, one is n ahead, increment until reaches end
        ListNode* first = head;
        ListNode* second = head;
        
        while (n > 0) {
            first = first->next;
            n--;
        }
        
        if (first == NULL) {
            ListNode* temp = second;
            second = temp->next;
            temp = NULL;
            return second;
        }
        
        while (first->next != NULL) {
            first = first->next;
            second = second->next;
        }
        
        ListNode* temp = second->next;
        second->next = temp->next;
        temp = NULL;
        
        return head;
    }
};