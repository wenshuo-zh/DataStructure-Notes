#include<bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
};

class Solution {
public:
	ListNode* headInsertStack(int n) {
		ListNode* dummyHead = new ListNode;
		dummyHead->next = nullptr;
		stack<int>stk;
		while (n--) {
			ListNode* p = new ListNode;
			cin >> p->val;
			
			p->next = dummyHead->next;
			dummyHead->next = p;
		}
		return dummyHead->next;
	}
	void printList(ListNode* head) {
		stack<int>stk;
		ListNode* temp = head;
		//遍历压栈
		while(temp){
			stk.push(temp->val);
			temp = temp->next;
		}
		while (!stk.empty()) {
			cout << stk.top() << " ";
			stk.pop();
		}
		cout << endl;
	}
};

int main() {
	Solution sol;
	int n;
	cin >> n;
	// 头插创建链表
	ListNode* link = sol.headInsertStack(n);
	// 栈打印正序
	sol.printList(link);
	return 0;
}
