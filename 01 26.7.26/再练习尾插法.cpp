#include<iostream>
using namespace std;

typedef struct Node {
	int val;
	Node* next;
}Node;
//链表只能从前一项找后一项
//头节点，极其重要，只能由他找到后面的数据
//虚头节点-创建一个节点，用来连接所有数据
//正真需要的数据-虚头节点的下一项
Node* createList(int n) {
	//创建一个长度为n的链表

	//1.创建虚头节点，用于连接数据
	Node* dummyHead = new Node;
	//Node* dummyhead1 = (Node*)malloc(sizeof(Node));
	dummyHead->next = nullptr;
	//尾插法需要记录尾部数据.
	Node* temp = dummyHead;
	while (n--) {
		//2.创建节点
		//2.1创建一个节点并输入数据
		Node* p = new Node;
		cin >> p->val;
		//2.2链接到链表上
		temp->next = p;
		p->next = nullptr;
		//p是最后一项
		//temp = p;
		temp = temp->next;
	}
	Node* realHead;
	realHead = dummyHead->next;
	delete dummyHead;
	return realHead;
}

void outputList(Node* head) {
	cout << "输出链表：" << endl;
	Node* temp = head;
	while (temp) {
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

void inputList(Node*& head) {
	int n;
	cout << "请输入链表的长度n：";
	cin >> n;
	cout << "请输入" << n << "个数据：" << endl;
	head = createList(n);
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
	Node* list = nullptr;
	inputList(list);
	outputList(list);
	freeList(list);
	return 0;
}