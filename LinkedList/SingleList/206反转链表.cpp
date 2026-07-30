
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummyHead = new ListNode;
        dummyHead->next = nullptr;
        for (ListNode* i = head; i; i = i->next) {
            ListNode* p = new ListNode;
            p->val = i->val;
            p->next = dummyHead->next;
            dummyHead->next = p;
        }
        return dummyHead->next;
    }
    
};