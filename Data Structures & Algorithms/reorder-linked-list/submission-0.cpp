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
    void reorderList(ListNode* head) {
        int size = 0;
        ListNode *temp = head;
        while(temp) {
            temp = temp->next;
            size++;
        }
        int hs = (size+1)/2;
        temp = head;
        ListNode *prevMid; 
        while(hs--) {
            prevMid = temp;
            temp = temp->next;
        }
        prevMid->next = nullptr; 

        ListNode * prev = nullptr;
        ListNode * curr;
        while(temp) {
            curr = temp; 
            temp = temp->next;
            curr->next = prev;
            prev = curr; 
        }

        ListNode* first = head;
        ListNode* second = prev;

        while(second) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;
            first->next = second;
            second->next = nextFirst;
            first=nextFirst;
            second=nextSecond;
        }
    }
};
