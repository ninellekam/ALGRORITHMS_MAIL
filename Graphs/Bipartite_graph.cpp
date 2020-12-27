#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	unordered_map<int, vector<int>> VEC;
	for (int i = 0; i < M; ++i) {
		int s, d;
		cin >> s >> d;
		VEC[s].push_back(d);
		VEC[d].push_back(s);
	}
	vector <char> color(N, '0');
	char col[2] = {'1', '2'};
	queue <int> QUEUE;
	for (int i = 0; i < N; i++) {
		if (VEC.find(i) != VEC.end() && color[i] == '0') {
			QUEUE.push(i);
			color[i] = col[0];
		}
		while (!(QUEUE.empty())) {
			int elem = QUEUE.front();
			QUEUE.pop();
			for (auto it : VEC[elem]) {
				if (color[it] == col[color[elem] - '1']) {
					cout << "NO\n";
					return (0);
				}
				if (color[it] == '0') {
					color[it] = col[((color[elem] - '1') + 1) & 1];
					QUEUE.push(it);
				}
			}
		}
	}
	cout << "YES\n";
	return 0;
}