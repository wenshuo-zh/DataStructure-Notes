#include<iostream>
#include<stack>
using namespace std;
int main() {

	stack<int>stk;
	//添加数据
	stk.push(1);
	stk.push(2);
	stk.push(3);
	//查看栈顶元素
	cout << stk.top() << endl;
	//删除元素
	stk.pop();
	//查看元素个数
	cout << stk.size() << endl;
	//判断是否为空
	cout << stk.empty() << endl;
}