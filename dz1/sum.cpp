#include <iostream>
#include <vector>
using namespace std;
long long change(vector <int> coins, int i, int m, long long n) {
    static long long k = 0;
    static long long minn = 9223372036854775807;
    static long long sum = 0;
    for (long long j = 0; j < 3 ; j++) {
        if (i >= m)
            break;
        sum += j*coins[i];
        i++;
        k = k + j;
        if (sum == n && k < minn)
            minn = k;
        change(coins, i, m, n);
        i--;
        sum -= j*coins[i];
        k = k - j;
    }     
    return minn; 
}

int main() {
    vector <int> coins;
    int m;
    long long n,a,sum = 0;
    long long min = 31;
    cin >> n >> m;
    for (int i = 0; i < n ; i++) {
        cin >> a;
        coins.push_back(a);
        sum += 2*a;
    }
    if (sum < n) {
        printf("Impossible");
        return (0);
    }
    long long ok = change(coins, 0, m, n);
    if ( ok >= min) 
        printf("Change");
    else
        printf("%lld", ok);
    return (0);
}
