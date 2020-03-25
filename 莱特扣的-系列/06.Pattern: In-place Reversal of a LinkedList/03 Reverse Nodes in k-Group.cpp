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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        int len = 0;
        while(p != NULL) {
            p = p->next;
            ++len;
        }
        p = head;
        int tol = len / k;
        ListNode* mid = p->next;
        ListNode *s1 = NULL, *s2 = NULL;
        ListNode *e1 = NULL, *e2 = NULL;
        int flag = 0;
        while(flag < tol) {
            int cnt = 1;
            flag % 2 == 0 ? e1 = p : e2 = p;
            while(cnt < k) {
                ListNode* temp = mid->next;
                mid->next = p;
                p = mid;
                mid = temp;
                ++cnt;
            }
            flag % 2 == 0 ? s1 = p : s2 = p;
            
            if(e2 != NULL) {
                flag % 2 == 0 ? e2->next = s1 : e1->next = s2;
            }
            if(flag == 0)
                head = p;
            p = mid;
            if(p != NULL)
                mid = p->next;
            ++flag;
        }
        flag % 2 == 0 ? e2->next = p : e1->next = p;
        return head;
    }
};
