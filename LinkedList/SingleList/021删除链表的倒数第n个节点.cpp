#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
	
		ListNode* dummyHead = new ListNode;
		ListNode* fast = head, * slow = dummyHead;
		dummyHead->next = head;
		while (n--) {
			fast = fast->next;
		}
		while (fast) {
			slow = slow->next;
			fast = fast->next;
		}
		slow->next = slow->next->next;
		return dummyHead->next;
	}
};