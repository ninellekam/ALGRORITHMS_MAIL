#include <iostream>
#include <vector>

using namespace std;
int main() {
    unsigned int a, k, n, m = 0, left = 0, right = 10000, mid = 0,max=0,sm=0, cnt = 0;
    vector<unsigned int> mas;
    unsigned int sum = 0;
    cin >> k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a > max) max = a;
        sm += a;
        mas.push_back(a);
    }
    left = max - 1;
    right = sm;
    bool flag=0;
    while (left < right - 1) {
        cnt = 0;
        sum = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < n; i++) {
            if (sum + mas[i] > mid) {
                cnt++;
                sum = 0;
            }
            sum += mas[i];
        }
        cnt++;
        if (cnt <= k ) {
            right = mid;
            flag = 0;
        }
        else {
            left = mid ;
            flag = 1;
        }
    }
    // if (flag==1) cout << left<< ' ';
    // else cout << right << ' ';
    cout << right;
    return 0;
}