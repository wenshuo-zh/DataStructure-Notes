#include<bits/stdc++.h>
using namespace std;

struct Node {
	int val;
	Node* next;
};

//new和malloc的区别
//malloc-free是c语言库函数，new-delete是运算符
//malloc需要指定开辟空间的大小，new不需要
//malloc只负责开辟空间，new除了可以开辟内存，还可以初始化
//malloc返回值是空指针void* ，需要强制类型转换；new返回值是对应类型的指针
//malloc开辟空间失败返回空指针，需要手动判断；new会抛出异常

//头插法
Node* createList(int n) {
	Node* dummyHead = new Node;
	dummyHead->next = nullptr;
	while (n--) {
		Node* p = new Node;
		cin >> p->val;
		p->next = dummyHead->next;
		dummyHead->next = p;
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
void freeList(Node* head)
{
	Node* cur = head;
	while (cur)     //cur != nullptr
	{
		Node* del = cur;
		cur = cur->next;
		delete del;
	}
}
int main() {
	int n;
	cout << "请输入链表的长度：";
	cin >> n;
	cout << "请输入" << n << "个数据：" << endl;
	Node* list = createList(n);
	printList(list);
	freeList(list);
	return 0;
}
