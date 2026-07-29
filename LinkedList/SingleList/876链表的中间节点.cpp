struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head, * slow = head;
        while (fast && fast->next)
        // && 是逻辑短路效应
        // && 左边为假，右边不会执行，防止 next 已经是 nullptr 时 next->next 访问野指针
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
