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
    ListNode* middleNode(ListNode* head) {
        ListNode *p = head, *mid = head;
        while(p != nullptr && p->next != nullptr) {
            mid = mid->next;
            p = p->next->next;
        }
        return mid;
    }
};
