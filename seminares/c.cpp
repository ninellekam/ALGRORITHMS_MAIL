#include <iostream>
using namespace std;

int lcs_length(string a, string b) {
	int *X, *Y;
	int M = a.length();
	int N = b.length();
	if (N > M) {
		int g = M;
		M = N;
		N = g;
	}
	X = new int [M];
	Y = new int [N];
	for (int i = M; i >= 0; i--) {
		for (int j = N; j >= 0; j--) {
			if (a[i] == '\0' || b[j] == '\0')
				X[j] = 0;
			else if (a[i+1] == b[j+1])
				X[j] = 1 + Y[j+1];
			else
				X[j] = max(Y[j], X[j+1]);
		}
		Y = X;
	}
	return X[0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;
	cout << lcs_length(a, b);

}