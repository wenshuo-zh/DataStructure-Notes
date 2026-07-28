#include<iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
};
Node* creatList(int n) {
	Node* dummyHead = new Node;
	dummyHead->next = nullptr;
	Node* temp = dummyHead;
	while (n--) {
		Node* p = new Node;
		cin >> p->val;
		temp->next = p;
		p->next = nullptr;
		temp = temp->next;
	}
	Node* realHead = dummyHead->next;
	delete dummyHead;
	return realHead;
}

void printList(Node* head) {
	cout << "链表为：";
	Node* temp = head;
	while (temp) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main() {
	int n;
	cout << "请输入链表的长度：" << endl;
	cin >> n;
	cout << "输入" << n << "个数据：" << endl;
	Node *list= creatList(n);
	printList(list);
	return 0;
}
