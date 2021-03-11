#include<stdio.h>
#include<vector>
#include <iostream>
using namespace std;

int main() {
    unsigned n = 0, max = 0, count = 0;
    scanf("%u", &n);
    vector<int> v(86402, 0);
    for (unsigned i = 0; i < n; ++i) {
        unsigned h = 0, m = 0, s = 0;
        scanf("%u:%u:%u", &h , &m , &s);
        v[(h*3600 + m*60 +s)]++;
     //   cout << " first " << h*3600 + m*60 +s << endl;
        scanf("%u:%u:%u", &h , &m , &s);
        v[(h*3600 + m*60 +s) + 1]--;
      //  cout << " second " << h*3600 + m*60 +s << endl;
    }
    for (unsigned i = 0; i < 86400; ++i) {
        if (v[i] > 0) {
            count += v[i];
            if (max < count)
                max = count;
        }
        else
          count += v[i];    
    }
    printf("%u", max);
    return 0;
}