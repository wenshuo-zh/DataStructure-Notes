#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int>que;
	//添加元素
	que.push(1);
	que.push(2);
	que.push(3);
	//查看队头队尾元素
	cout << "队头元素：" << que.front() << endl;
	cout << "队尾元素：" << que.back() << endl;
	//删除元素
	que.pop();
	que.pop();
	que.pop();
	//查看元素个数
	cout << "元素个数：" << que.size() << endl;
	//判断是否为空
	cout << que.empty() << endl;
}