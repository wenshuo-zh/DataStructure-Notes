#include<iostream>
#include<iomanip>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	cout << a << endl << b << endl;
	double k = 10000.0 / 3;
	printf("%lf\n", k);
	cout << k << endl;
	cout <<setw(10)<<setfill('.') << fixed << setprecision(3) << k << endl;
	//setw()²¹ÆëÎ»Êý
	//setfill()²¹ÆëµÄÌî³ä

	return 0;
}