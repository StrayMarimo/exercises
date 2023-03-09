#include <iostream>
using namespace std;

int sum(int,int);
int diff(int,int);
int prod(int,int);
int quo(int,int);

int main(void) {
	int n1, n2;
	cin >> n1 >> n2;

	cout << sum(n1, n2) << endl;
	cout << diff(n1, n2) << endl;
	cout << prod(n1, n2) << endl;
	cout << quo(n1, n2) << endl;
	return 0;
}

int sum(int n1, int n2) {
	return n1 + n2;
}

int diff(int n1, int n2) {
	return n1 - n2;
}

int prod(int n1, int n2) {
	return n1 * n2;
}

int quo(int n1, int n2) {
	return n1 / n2;
}


