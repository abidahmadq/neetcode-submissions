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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> min_pq;
        for(int i=0; i < lists.size(); i++) {
            ListNode* head = lists[i];
            min_pq.push({head->val, head});
        }
        
        ListNode *dummy = new ListNode(0); 
        ListNode *tail = dummy;

        while(!min_pq.empty()) {
            auto &it = min_pq.top();
            ListNode *temp = it.second;
            min_pq.pop();
            tail->next = temp;
            tail = tail->next;
            if(temp->next) min_pq.push({temp->next->val, temp->next});
        }
        return dummy->next;
    }
};
