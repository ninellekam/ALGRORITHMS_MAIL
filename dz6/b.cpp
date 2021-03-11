#include <unordered_set>
#include <vector>
#include <set>
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	// ios::sync_with_stdio(0);
	// cin.tie(0);

	set <multiset <int> > table;
	unsigned long long hash, a;
	unsigned long long N, M, K;

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		multiset <int> etalon;
		for (int j = 0; j < M; j++) {
			cin >> a;
			etalon.insert(a);
		}
		table.insert(etalon);
	}
	for (int i = 0; i < K; i++) {
		multiset <int> prob;
		for (int j = 0; j < M; j++) {
			cin >> a;
			prob.insert(a);
		}
		if (table.find(prob) != table.end())
			printf("1\n");
		else
			printf("0\n");
	}
}