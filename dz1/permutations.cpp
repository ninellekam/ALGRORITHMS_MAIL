#include <iostream>
#include <vector>
using namespace std;

long long fact(long n)
{
    if(n < 0) 
        return 0; 
    if (n == 0) 
        return 1; 
    else 
        return n * fact(n - 1); 
}

int znain() {
    int n;
    long long m ;
    cin >> n;
    vector <int> number(n+1,0);
    cin >> m;

    // long long fact[21] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 
    // 6227020800, 87178291200, 1307674368000, 20922789888000,	355687428096000, 6402373705728000 ,121645100408832000,	2432902008176640000};
    vector <int> res;
    long long np, d = 0, num = m;
    long long fact_al = fact(n);
    for (int i = n; i > 0; --i) {
        fact_al = fact_al / i;
        np = num % fact_al ;   
        d = num / fact_al;  
        if (np) 
            d++;
        else 
            np += fact_al;
        num = np;
        int pos = 0;
        for (int j = 1; j <= n; ++j) {   
            if (!number[j]) 
                pos++;
            if (pos == d) {
                number[j] = 1;
                res.push_back(j);   
                break;
            }
        }
    }
    for (auto it : res) {
        cout << it << " ";
    }
    return (0);
}