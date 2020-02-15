/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        map<int, int> mm;
        ListNode* p = pHead;
        while(p) {
            if(mm.find(p->val) != mm.end())
                ++mm[p->val];
            else
                mm[p->val] = 1;
            p = p->next;
        }
        while(pHead) {
            if(mm[pHead->val] > 1)
                pHead = pHead->next;
            else
                break;
        }
        p = pHead;
        while(p && p->next) {
            if(mm[p->next->val] > 1)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return pHead;
    }
};
