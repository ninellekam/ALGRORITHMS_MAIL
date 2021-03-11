#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int main() {
    int N, M, count = 0;
	scanf("%d %d", &N, &M);
	unordered_map<unsigned long long, set<int>> interval;  // map of set of indexies
	unordered_set<unsigned long long> cache; // cashe
	vector<unsigned long long> vec(M); // vector of elements(values)
	vector< pair<int, unsigned long long> > BH; // save all elements and they priorities

	for(int i = 0; i < M; ++i) {
		unsigned long long tmp;
		scanf("%llu", &tmp);
		interval[tmp].insert(i);

		vec[i] = tmp;
	}

	int priority;
	unsigned long long val = 0;

	for(int i = 0; i < M; ++i) {
		for(int d = 0; d < BH.size(); ++d)
			BH[d].first -= 1; // priority -1
		interval[vec[i]].erase(interval[vec[i]].begin());
		if(cache.find(vec[i]) == cache.end()) { // if not found in cashe count++
			++count;
			if(cache.size() < N) {
				cache.insert(vec[i]); // insert curr element
				if(interval[vec[i]].empty())
					priority = 1000000; // set the priority
				else
					priority = *(interval[vec[i]].begin())-i;
				BH.push_back({priority, vec[i]});
			}
			else {
				int num = 0, pr = BH[0].first; // index and priority for max_priority element wich is erased
				auto it = BH.begin(), max_it = BH.begin();
				for(int d = 1; d < BH.size(); ++d) {
					it++;
					if(BH[d].first > pr) {
						num = d; // index
						pr = BH[d].first; // priority
						max_it = it; // bh[index] of biggest priority
					}
				}
				unsigned long long k = BH[num].second;
				BH.erase(max_it); // erase the element of biggest priority
				cache.erase(k); // erase by cashe
				cache.insert(vec[i]);	// insert curr element
				if(interval[vec[i]].empty())
					priority = 1000000; // set the priority
				else
					priority = *(interval[vec[i]].begin())-i; // set the priority of
				BH.push_back({priority, vec[i]});
			}
		}
		else {
			for(int d = 0; d < BH.size(); ++d)
				if(BH[d].second == vec[i]) {
					if(interval[vec[i]].empty())
						priority = 1000000;
					else
						priority = *(interval[vec[i]].begin())-i;
					BH[d].first = priority;
					break;
				}
		}
	}
	printf("%d", count);
	return 0;
}
