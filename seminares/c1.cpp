#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;


int getLongestCommonSubsequence(const string& a, const string& b)
    {
        vector<vector<int> > max_len;
        max_len.resize(a.size() + 1);
        for(int i = 0; i <= static_cast<int>(a.size()); i++)
            max_len[i].resize(b.size() + 1);
        for(int i = static_cast<int>(a.size()) - 1; i >= 0; i--)
        {
            for(int j = static_cast<int>(b.size()) - 1; j >= 0; j--)
            {
                if(a[i] == b[j])
                {
                    max_len[i][j] = 1 + max_len[i+1][j+1];
                }
                else
                {
                    max_len[i][j] = max(max_len[i+1][j], max_len[i][j+1]);
                }
            }
        }
        string res;
        for(int i = 0, j = 0; max_len[i][j] != 0 && i < static_cast<int>(a.size()) && j < static_cast<int>(b.size()); )
        {
            if(a[i] == b[j])
            {
                res.push_back(a[i]);
                i++;
                j++;
            }
            else
            {
                if(max_len[i][j] == max_len[i+1][j])
                    i++;
                else
                    j++;
            }
        }
        return res.length();
    }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	printf("%d", getLongestCommonSubsequence(a, b) );
}