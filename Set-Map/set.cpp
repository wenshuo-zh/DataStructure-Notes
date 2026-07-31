#include<bits/stdc++.h>
using namespace std;
int main() {
	//set
	//1.自动去重
	//2.默认升序排列
	vector<int>vec = { 1,0,77,23,13,7,11,6,91,35,30 };
	//可以使用迭代器
	set<int>s(vec.begin(), vec.end());
	for (int i = 0; i < s.size(); i++) {
		//next（迭代器，偏移量）
		//auto自动识别类型
		auto it = next(s.begin(), i);//当前位置上数据的指针
		cout << *it << " ";

	}
	cout << endl;
	//insert(数据)添加数据，自动找到合适的地方
	//没有push()
	s.insert(99);
	//find、count
	
	//count 查找数据 返回值为int 找到了为1未找到为0
	if (s.count(7))cout << "存在数据7" << endl;
	else cout << "不存在数据7" << endl;
	//find 返回值是迭代器 找到返回这个数据的指针 未找到返回end()
	auto it = s.find(7);
	if (it != s.end())cout << "存在数据" << *it << endl;
	else cout << "未找到数据" << endl;
	
	//删除数据
	s.erase(6);

}