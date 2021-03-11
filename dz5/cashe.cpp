#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>

using namespace std;


int main() {
  unsigned long long N, M, cnt = 0;
  unordered_map <unsigned long long, set<int>> interval;
  unordered_set <unsigned long long> cashe;
  vector < pair <int, unsigned long long> > MEMORY;

  scanf("%d %d", &N, &M);
  vector <unsigned long long> elems(M);
  for (int i = 0; i < M; i++) {
    unsigned long long tmp;
    cin >> tmp;
    interval[tmp].insert(i);
    elems[i] = tmp;
  }

  int priority;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < MEMORY.size(); j++)
        MEMORY[j].first -= 1;
    interval[elems[i]].erase(interval[elems[i]].begin());

// ---------------IF NOT IN CACHE -------------------------------------------------------------
    if (cashe.find(elems[i]) == cashe.end()) {
        cnt++;
        if (cashe.size() < N) {
            cashe.insert(elems[i]);
            if (interval[elems[i]].empty()) 
                priority = 1000000;
            else
                priority = *(interval[elems[i]].begin()) - i;
            MEMORY.push_back(make_pair(priority, elems[i]));
        }
        else {
			unsigned long long curr_idx_max = 0, curr_pr = MEMORY[0].first; // index and priority for max_priority element wich is erased
			auto it = MEMORY.begin();
            auto max_it = it;
				for(int d = 1; d < MEMORY.size(); ++d) {
					it++;
					if(MEMORY[d].first > curr_pr) {
						curr_idx_max = d; // index 
						curr_pr = MEMORY[d].first; // priority
						max_it = it; // bh[index] of biggest priority 
					}
				}
				unsigned long long k = MEMORY[curr_idx_max].second;
				MEMORY.erase(max_it); // erase the element of biggest priority
				cashe.erase(k); // erase by cashe
				cashe.insert(elems[i]);	// insert curr element

				if(interval[elems[i]].empty())
					priority = 1000000; // set the priority 
				else
					priority = *(interval[elems[i]].begin())-i; // set the priority of 
        
				MEMORY.push_back(make_pair(priority, elems[i]));
			}
    }
//---------------------- IF IN CASHE -------------------------------------------------------------
    else 
      for (int d = 0; d < MEMORY.size(); d++) {
        if (MEMORY[d].second == elems[i]) {
			if(interval[elems[i]].empty())
				priority = 1000000; 
			else
			    priority = *(interval[elems[i]].begin())-i;
			MEMORY[d].first = priority;
			break;
        }
    }
  }
  printf("%d", cnt);  
  return (0);
}