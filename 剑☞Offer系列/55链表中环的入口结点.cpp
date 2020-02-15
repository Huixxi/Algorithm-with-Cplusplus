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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        map<ListNode*, int> mm;
        while(pHead) {
            if(mm.find(pHead) != mm.end())
                ++mm[pHead];
            else
                mm[pHead] = 1;
            if(mm[pHead] == 2)
                return pHead;
            pHead = pHead->next;
        }
        return nullptr;
    }
};
