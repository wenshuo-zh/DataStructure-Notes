#include<iostream>
#include<deque>
using namespace std;
int main() {
	deque<int>deq;
	deq.push_back(5);//放到队尾
	deq.push_front(8);//放到队头

	//下标访问数据
	cout << deq[0] << endl;

	cout << deq.back() << endl;
	cout << deq.front() << endl;

	deq.pop_back();
	deq.pop_front();
}