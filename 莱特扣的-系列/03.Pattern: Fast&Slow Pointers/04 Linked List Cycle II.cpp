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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        int len = 0, flag = 0;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(flag == 1) 
                ++len;
            if(fast == slow) {
                if(flag == 0)
                    flag = 1;
                else
                    break;
            }
        }
        if(len != 0) {
            fast = head;
            slow = head;
            while(len > 0) {
                fast = fast->next;
                --len;
            }
            while(fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
        else
            return nullptr;
    }
};
