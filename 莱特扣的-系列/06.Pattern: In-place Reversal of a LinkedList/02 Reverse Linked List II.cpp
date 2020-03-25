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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int cnt = 1;
        ListNode* p = head;
        while(p != NULL && p->next != NULL) {
            if(cnt < m - 1) {
                p = p->next;
                ++cnt;
                continue;
            }
            ListNode* q = p;
            ListNode* temp2 = p->next;
            if(m != 1) {
                p = p->next;
                temp2 = p->next;
                ++cnt;
            }
            while(cnt < n && p != NULL && p->next != NULL) {
                ListNode* temp = temp2->next;
                temp2->next = p;
                p = temp2;
                temp2 = temp;
                ++cnt;
            }
            if(m == 1) {
                q->next = temp2;
                head = p;
            }
            else{
                q->next->next = temp2;
                q->next = p;
            }
            break; 
        }
        return head;
    }
};
