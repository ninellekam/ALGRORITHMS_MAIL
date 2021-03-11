#include <iostream>
#include <vector>
using namespace std;

//-----------------  algo Eratosthenes ---------------------

int main() {
    unsigned        i, j,length,  count = 0;
    unsigned      M , N;
    int             carry;
    scanf("%u", &M);
    scanf("%u", &N);
    length =  20000000 + N;
    vector <bool>   vect(length+1);
    for (unsigned i = 2; i <= length ; ++i) 
    {
        if (!vect[i]) {  // 0 - prime , 1 - sostavnoe
            for (int j = 2*i; j <= length; j+=i) 
                vect[j] = 1;
        }
        count += !(vect[i]); 
        carry = (int)(i - N);
        if (count == M && (carry >= 2)) {
            printf("%u" , ++carry);
            return (0);
        }
        if (carry >= 2)  
            count -= !(vect[i - N]); 
    }
    printf("-1");
    return (0);
}