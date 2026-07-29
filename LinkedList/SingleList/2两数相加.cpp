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
        ListNode* dummyHead = new ListNode(0);
        ListNode* tail = dummyHead;
        bool IsCarry = false;

        while (l1 || l2 || IsCarry) {
            int sum = IsCarry ? 1 : 0;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }

            IsCarry = (sum >= 10);
            if (IsCarry) sum -= 10;

            tail->next = new ListNode(sum);
            tail = tail->next;
        }

        return dummyHead->next;
    }
};
