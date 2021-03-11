#include <iostream>

using namespace std;

int main () {
    long long count[26] = {};
    char c;

    while (cin >> c) {
        count[c - 'A']++;
    }
    long long carry, sort_count[26];
    for (int i = 0 ; i < 26 ; i++){
        sort_count[i] = count[i];
    }
    bool ok = true ;
    while (ok) {
        ok = false;
        for (int i = 0; i < 25; i++) {
            if (sort_count[i+1] > sort_count[i]) {
                ok = true;
                carry = sort_count[i];
                sort_count[i] = sort_count[i + 1];
                sort_count[i + 1] = carry;
            }
        }
    }
    int j = -1;

	for (int i = 0; i < 26 && sort_count[i]; i++) {
	if (i && sort_count[i-1] != sort_count[i]) 
        j = -1;
	while (count[++j] != sort_count[i]);
	cout << (char)('A'+j) << ' ' << count[j] << "\n";
	}
}