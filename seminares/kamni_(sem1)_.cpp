#include <stdio.h>

int znain() {
    unsigned n;
    scanf("%u" , &n);
    unsigned w[23];
    unsigned total = 0;
    for (unsigned i=0; i<n; i++) {
        scanf("%u" , &w[i]);
        total += w[i];
    }

    const unsigned lim = 1u << n;
    unsigned result = -1; // очень большое число 
    for (unsigned gen = 0; gen < lim; gen++) {
        unsigned cur = 0; //  sum of kuna
        unsigned t = gen;
        for (unsigned bitnum = 0; t != 0; bitnum++) {
           cur += w[bitnum]*(t & 1);
           t >>= 1;
        }
        int delta = total - cur - cur;
        if (delta < 0) delta = -delta;
        if ((unsigned)delta < result) {
            result = delta;
        }
    }
    printf("%u\n", result);
}