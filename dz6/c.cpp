#include <iostream>
#include <unordered_map>
#include <string>
//#include <algorithm>
#include <vector>
#include <stdio.h>

#define CHISELKA 5

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	unsigned long long N, M;
	int elem;
	cin >> N >> M;
	std::vector <unsigned long long> vec(1000, 1);
	for (int i = 1; i < M; i++)
		vec[i] = vec[i - 1] * CHISELKA;

	std::vector<unsigned long long> table_hash(1000, 0);
	for (int i = 1; i < M + 1; i++) {
		cin >> elem;
		table_hash[i] = table_hash[i - 1] + (elem)*vec[i - 1];
	}

	unsigned long long mx = 0;
	for (int i = 0; i < N; i++) {
		std::unordered_map <unsigned long long, int> mymap;
		unsigned long long chiselka_2 = 1, hash;
		for (int j = 1; j < M; j++) {
			cin >> elem;
			hash = elem * chiselka_2;
			if (mymap.find(hash) != mymap.end())
				mymap[hash]++;
			else
				mymap[hash] = 1;
			if (mymap[hash] * i > mx)
				mx = mymap[hash] * i;

			chiselka_2 *= CHISELKA;
		}
	}

	printf("%llu\n", mx);
	return (0);
}