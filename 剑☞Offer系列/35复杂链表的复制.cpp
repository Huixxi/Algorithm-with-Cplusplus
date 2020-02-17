/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return nullptr;
        // 复制
        RandomListNode* p = pHead;
        while(p) {
            RandomListNode* temp = new RandomListNode(p->label);
            temp->next = p->next;
            p->next = temp;
            p = temp->next;
        }
        // 赋值
        p = pHead;
        while(p) {
            if(p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        // 拆分
        RandomListNode* newHead = pHead->next;
        RandomListNode* temp = nullptr;
        p = pHead;
        while(p) {
            temp = p->next->next;
            if(temp != nullptr)
                p->next->next = temp->next;
            p->next = temp;
            p = p->next;
        }
        return newHead;
    }
};
