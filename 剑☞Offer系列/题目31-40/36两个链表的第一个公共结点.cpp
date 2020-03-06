/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int l1 = 0, l2 = 0;
        ListNode* p = pHead1;
        ListNode* q = pHead2;
        while(p || q) {
            if(p) {
                ++l1;
                p = p->next;
            }
            if(q) {
                ++l2;
                q = q->next;
            }
        }
        if(l1 > l2) {
            for(int i = 0; i < l1 - l2; ++i) 
                pHead1 = pHead1->next;
        }
        else {
            for(int i = 0; i < l2 - l1; ++i) 
                pHead2 = pHead2->next;
        }
        while(pHead1) {
            if(pHead1 == pHead2)
                return pHead1;
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return nullptr;
    }
};
