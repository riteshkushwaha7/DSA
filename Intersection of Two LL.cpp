class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int>mpp;
        ListNode* c1 = headA;
        ListNode* c2 = headB;

        while(c1){
            mpp[c1] = 1;
            c1 = c1->next;
        }
        while(c2){
            if(mpp.count(c2)==1)
            return c2;

            mpp[c2] = 1;
            c2 = c2->next;
        }
        return nullptr;
    }
};
