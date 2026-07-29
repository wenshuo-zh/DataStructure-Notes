#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // l1, l2 全是非空
        ListNode* dummyHead = new ListNode;
        dummyHead->next = nullptr;
        ListNode* list = dummyHead;
        while (l1 && l2) {
            bool IsCarry = false;
            list->val = l1->val + l2->val;
            if (list->val >= 10) {
                list->val -= 10;
                IsCarry = true;
            }
        }
    }
};
