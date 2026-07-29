#include<iostream>
using namespace std;

typedef struct Node {
	int val;
	Node* next;
}Node;
//链表只能从前一个找后一个
//头节点，不需要存数据，只用来找到链表开头
//虚头节点-不存数据的第一个节点，纯粹为了方便操作
//尾插法需要维护尾指针-指向头节点最后一个
Node* creatList(int n) {
	//创建一个长度为n的链表

	//1.创建虚头节点，方便后续操作
	Node* dummyHead = new Node;
	//Node* dummyhead1 = (Node*)malloc(sizeof(Node));
	dummyHead->next = nullptr;
	//尾插法：需要记录尾结点位置
	Node* temp = dummyHead;
	while (n--) {
		//2.创建节点
		//2.1创建一个节点并输入数据
		Node* p = new Node;
		cin >> p->val;
		//2.2连接到链表上
		temp->next = p;
		p->next = nullptr;
		//p变成最后一个
		//temp = p;
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
	Node* list = creatList(n);
	printList(list);
	freeList(list);
	return 0;
}
