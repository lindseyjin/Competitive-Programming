
/*
https://leetcode.com/problems/add-two-numbers/
2019-04-05
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *curr = ans;
        ListNode *ptr1 = l1;
        ListNode *ptr2 = l2;
        int nextVal = 0;
        
        while (ptr1 != NULL || ptr2 != NULL) {
            if (ptr1 != NULL) {
                nextVal += ptr1->val;
                ptr1 = ptr1->next;
            }
            if (ptr2 != NULL) {
                nextVal += ptr2->val;
                ptr2 = ptr2->next;
            }
            
            // make next node if more numbers to add, or if carry over exists
            if (curr->val + nextVal >= 10) {
                curr->next = new ListNode(1);
                nextVal = nextVal - 10;
            } else if (ptr1 != NULL || ptr2 != NULL) { // don't want a leading 0
                curr->next = new ListNode(0); 
            }
            
            curr->val += nextVal;
            curr = curr->next;
            nextVal = 0;
        }
        
        return ans;
    }
};