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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *forward = dummy;
        while(n-- && forward) {
            forward = forward->next;
        }
        ListNode *ptr, *prev;
        ptr = dummy;
        while(forward) {
            forward = forward->next;
            prev = ptr;
            ptr = ptr->next;
        }
        ListNode *temp = ptr->next;
        prev->next = temp;
        delete ptr;
        return dummy->next;
    }
};
