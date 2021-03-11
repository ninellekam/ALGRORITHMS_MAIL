#include <iostream>
using namespace std;

int main() {
    long long dfive = 0;
    long long count = 0;
    long long n;
    cin >> n;
    for (long long i = 0; i < n ; i++) {
        long long a;
        cin >> a;
        if (a == 5)
            count--;
        else
            count += a/5 - 1;
        if (count > dfive)
            dfive = count;  
    }
         if (count <= 0)
            count = 0;  
    cout << dfive  << endl;
    return (0);
}