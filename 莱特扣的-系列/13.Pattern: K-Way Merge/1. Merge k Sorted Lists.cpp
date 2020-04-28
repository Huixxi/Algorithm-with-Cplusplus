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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< int, vector<int>, greater<> > pq;
        for(auto& head : lists) {
            while(head != nullptr) {
                pq.push(head->val);
                head = head->next;
            }
        }
        if(pq.empty())
            return nullptr;
        ListNode* p = new ListNode(pq.top());
        ListNode* res = p;
        pq.pop();
        while(!pq.empty()) {
            p->next = new ListNode(pq.top());
            pq.pop();
            p = p->next;
        }
        return res;
    }
};
