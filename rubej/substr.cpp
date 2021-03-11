#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

vector<int> zFunction (string s) {
	int n = (int) s.length();
	vector<int> z (n);
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
	return z;
}

long long  countSub(string s) 
{ 
  vector<int> m(s.length(), 0);
  long long answer = 0;
    for (int i = 0; i < s.length() ; i++) { 
        auto z = zFunction(s.substr(i)); 
        answer += s.length() - i - m[i];
        for (int j = i + 1; j < s.length(); j++)
            m[j] = max(m[j], z[j - i]); 
    }
    return answer;
}


// Driver Code 
int main() 
{ 
    string str ; 
    cin >> str;
    cout << countSub(str); 
  
    return 0; 
}
  
