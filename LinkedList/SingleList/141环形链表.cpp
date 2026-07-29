#include<bits/stdc++.h>
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
     /*   ListNode* sign = new ListNode(1);
        sign->next = head;
        while (sign) {
            if(sign->val==sign)
            sign->val++;
        }*/

        ListNode* fast = head, * slow = head->next;
        if (!head)return false;
        while (fast && fast->next) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};