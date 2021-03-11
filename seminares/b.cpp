#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <stdio.h>

#define PR 5
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	vector <string> vec_str;

	vector<unsigned long long> ptab(str.size(), 1);
	for(int i = 1; i < str.size(); ++i)
		ptab[i] = ptab[i-1]*PR;

	vector<unsigned long long> htab(str.size()+1, 0);
	for (unsigned i = 1; i <= str.size(); i++)
		htab[i] = htab[i-1] + (str[i-1]-'A'+1)*ptab[i-1];

	for (int len = 1; len < str.size()+1; ++len) {
		unordered_map<unsigned long long, int> MAP;
		unsigned long long K = 1;
		for (int i = str.size() - len; i >= 0;  --i) {
			unsigned long long hash = (htab[i+len]-htab[i])*K;
			if(MAP.find(hash) == MAP.end())
				MAP[hash] = 1;
			else
				MAP[hash] += 1;
			if (MAP[hash] >= 2) {
				vec_str.push_back(str.substr(i + len + 1, i));
			}
			K *= PR;
		}

		MAP.clear();
	}
	string max = "";
	for (auto it : vec_str) {
		if (it.length() > max.length()) {
			max = it;
		}
	}
	printf("%s", max.c_str());
}