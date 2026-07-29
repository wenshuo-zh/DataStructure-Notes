struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* temp = dummyHead;
        while (temp->next) {
            if (temp->next->val == val)
                temp->next = temp->next->next;
            // 删除数据后 temp->next 改变，不能直接指向 next，否则会漏判断下一个节点
            // 没删数据才后移
            else
                temp = temp->next;
        }
        return dummyHead->next;
    }
};
