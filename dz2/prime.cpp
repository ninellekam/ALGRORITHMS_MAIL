#include <string.h>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;
#define LIMIT 20000000
typedef unsigned  word_t;

int check(word_t *primes, unsigned i) {
    return ((primes[i / 32] >> (i % 32)) & 1);
}

void clear(word_t *primes, unsigned i) { 
     primes[i / 32] &= ~(1 << (i % 32));
}

int main() 
{
    unsigned i, j,  length;
    unsigned M , N, count = 0;
    int carry;
    scanf("%u", &M);
    scanf("%u", &N);
    length = LIMIT / 32 + 1;
    word_t *primes= new word_t [length]; 
    memset(primes, INT_MAX, length);

    for ( i = 2; i < LIMIT; i++) {
        if (check(primes, i)) {
            for ( j = i; i * j < LIMIT; j++)
                clear(primes, i * j);  
        }   
        count += (check(primes,i)); 
        carry = (int)(i - N);
        if (carry >= 2 )  
            count -= (check(primes,i - N)); 
        if (count == M && !(carry < 2)) {
            printf("%d" , ++carry);
            return (0);
        } 
    }  
    printf("-1");        
    return 0;
}