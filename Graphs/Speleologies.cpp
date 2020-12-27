#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

unsigned long long inf = 1e12;
unsigned long long N, M, K, S, F;

void	DEIKSTRA(unsigned long long F, map <unsigned long long,
				vector<pair<long long, long long>>> &REBRA, vector <unsigned long long> &D) {
	vector <unsigned long long> color(N, 0);
	queue <unsigned long long> Q;

	Q.push(F);
	D[F] = 0;
	color[F] = 1;

	while(!(Q.empty())) {
		long long curr = Q.front();
		Q.pop();
		color[curr] = 1;
		vector<pair<long long, long long>> tmp = REBRA[curr];
		sort(tmp.begin(), tmp.end());
		for(auto elem: tmp) {
			if(color[elem.first] == 0)
				Q.push(elem.first);
			if (D[elem.first] > D[curr] + elem.second) {
				D[elem.first] = D[curr] + elem.second;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector <unsigned long long> f(K);
	vector <unsigned long long> D(N, inf);
	map <unsigned long long, vector<pair<long long, long long>> > REBRA;

	for (int i = 0; i < K; i++) {
		cin >> f[i];
		--f[i];
	}
	for (int i = 0; i < M; i++) {
		long long s, d, w;
		cin >> s >> d >> w;
		--s; --d;
		REBRA[s].push_back(make_pair(d, w));
		REBRA[d].push_back(make_pair(s, w));
	}
	cin >> S >> F;
	--S; --F;
	DEIKSTRA(F, REBRA, D);
	if (D[S] == inf) {
		cout << -1;
		return (0);
	}
	unsigned long long min = inf;
	for (int i = 0; i < K; i++) {
		if (D[f[i]] < min)
			min = D[f[i]];
	}
	if (min <= D[S]) {
		cout << -1;
		return (0);
	}
	else
		cout << D[S];

	return (0);
}
