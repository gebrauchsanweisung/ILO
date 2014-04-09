#include <iostream>

using namespace std;

void col(int n, int i) {
	cout << n << " " << i << "\n";
	if (n>1) {
		if (n%2>0)
			col(3*n+1, i+1);
		else
			col(n/2, i+1);
	}
}

int main() {
	int n;
	cin >> n;
	int i = 0;
	col(n, i);
	cin.ignore(1,5);
	return 0;
}
