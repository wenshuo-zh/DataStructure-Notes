#include<bits/stdc++.h>
using namespace std;

int main() {
	//字符串和字符数组的区别 '\0'
	// string 基础操作

	string s1;
	string s2 = "hello";
	cout << s2 << endl;
	string s3 = s2;
	//重复字符
	string s4(6, 'a');
	cout << s4 << endl;
	//截取字符
	string s5("hello word", 5);
	cout << s5 << endl;
	//length() - size() 求取长度 有效数据位
	cout << "s2.size()" << s2.size() << endl;
	//判定是否为空
	cout << "s2.empty()" << s2.empty() << endl;
	//拼接字符串
	s2 += "world";
	cout << s2 << endl;
	//指定位置添加数据
	//insert(位置下标,字符串类型)
	s2.insert(5, " ");
	cout << s2 << endl;
	//截取替换
	//replace(替换起点,替换位数,替换的字符串)
	s2.replace(6, 3, "string");
	cout << s2 << endl;
	//截取数据substr(截取起点,截取位数)
	string s6 = s2.substr(6, 6);
	cout << s6 << endl;

	//数据类型转换
	//string变int
	string s7 = "2345";
	int num1 = stoi(s7);
	cout << num1 + 100 << endl;
	//int变string
	int num2 = 1234;
	string s8 = to_string(num2);
	cout << s8 << endl;

	//字符串比较 - 字典序 > < <= >= ==

	//输入字符串
	//cin：遇到空格或换行就结束
	//getline(cin,s9)
	string s9;
	cout << "请输入一行文字：";
	getline(cin, s9);
	cout << s9 << endl;

	return 0;
}
