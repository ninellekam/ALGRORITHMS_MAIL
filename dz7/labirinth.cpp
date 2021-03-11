#include <iostream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

int N, M;


unsigned long long func(int x, int y, int K, vector <vector <char> > vec, map<tuple<int, int, int>, unsigned long long> &mymap) {
	unsigned long long cnt = 0;
	if (vec[x][y] == '#' && K == 0)
		return (1);
	if (K == 0)
		return (0);
	if (mymap.find(make_tuple(x, y, K)) != mymap.end())
		return (mymap[make_tuple(x, y, K)]);
	if ((x + 1) < N && vec[x + 1][y] != '+' )
		cnt += func(x + 1, y, K - 1, vec, mymap);
	if ((y + 1) < M && vec[x][y + 1] != '+')
		cnt += func(x, y + 1, K - 1, vec, mymap);
	if ((x - 1) >= 0 && vec[x - 1][y] != '+' )
		cnt += func(x - 1, y, K - 1, vec, mymap);
	if ((y - 1) >= 0 && vec[x][y - 1] != '+')
		cnt += func(x, y - 1, K - 1, vec, mymap);

	mymap[make_tuple(x, y, K)] = cnt;
	return (cnt);
}

int main() {
	int x, y, K;
	cin >> N >> M >> K;
	map <tuple < int, int, int>, unsigned long long > mymap;
	vector <vector <char> > vec(M, vector <char> (M));
	for (int  i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> vec[i][j];
			if (vec[i][j] == '@') {
				x = i;
				y = j;
			}
		}
	}
	cout << func(x, y, K, vec, mymap);
}