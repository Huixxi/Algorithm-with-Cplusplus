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
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = head;
        if(head->next != NULL)
            reverseList(head->next)->next = newHead;
        newHead->next = NULL;
        return newHead;
    }
};
