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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode;
        dummyHead->next = head;
        ListNode* fast = head;
        ListNode* slow = dummyHead;
        //快慢指针中间差n个节点
        //快指针从head先走n步
        while (n--) {
            fast = fast->next;
        }
        //快指针走到nullptr时，慢指针停到需要的位置上
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        //slow停在被删数据的前一项
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};