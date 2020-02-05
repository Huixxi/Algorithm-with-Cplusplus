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
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* newHead = NULL;
        ListNode* temp = NULL;
        while(pHead != NULL) {
            temp = pHead->next;
            pHead->next = newHead;
            newHead = pHead;
            pHead = temp;
        }
        return newHead;
    }
};
