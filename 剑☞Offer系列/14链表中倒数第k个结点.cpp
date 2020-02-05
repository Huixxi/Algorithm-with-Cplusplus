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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k == 0)
            return NULL;
        ListNode* h = pListHead;
        ListNode* hk = pListHead;
        int count = 1;
        while(hk->next != NULL && count < k) {
            hk = hk->next;
            ++count;
        }
        if(count < k)
            return NULL;
        while(hk->next != NULL) {
            h = h->next;
            hk = hk->next;
        }
        return h;
    }
};
