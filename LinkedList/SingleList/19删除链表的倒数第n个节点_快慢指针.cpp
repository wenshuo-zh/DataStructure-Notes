struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode;
        dummyHead->next = head;
        ListNode* fast = head;
        ListNode* slow = dummyHead;
        // 快慢指针中间隔 n 个节点
        // 快指针从 head 往后走 n 步
        while (n--) {
            fast = fast->next;
        }
        // 快指针走到 nullptr 时，慢指针停在要删除节点的前一个
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        // slow 停在被删节点的前一个
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};
