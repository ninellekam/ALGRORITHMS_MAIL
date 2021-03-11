
#include <iostream>
using namespace std;


int main () {
//	cout << 0x000000FFU ;
	unsigned long K, L, M, N;
	unsigned long sum = 0;
	
	cin >> N >> K >> M >> L;
	
	unsigned int a[N], b[N], count1[2][256] = {}, count2[2][256] = {}, count3[2][256] = {}, count4[2][256] = {};

	a[0] = K;
	for (long i=1; i<N; i++) {
		a[i] = (unsigned int)((a[i-1]*(unsigned long long)M )&0xFFFFFFFFU);
		a[i] = a[i]%L;
	}

//++++ 8-0 bits sorting ++++	
	for (long i=0; i<N; i++) {
		count1[0][a[i] & 0x000000FFU]++;
		count2[0][(a[i] >> 8) & 0x000000FFU]++;
		count3[0][(a[i] >> 16) & 0x000000FFU]++;
		count4[0][(a[i] >> 24)]++;
	}
	
	for (int i=1; i<256; i++) {
		count1[1][i] = count1[0][i-1] + count1[1][i-1];
		count2[1][i] = count2[0][i-1] + count2[1][i-1];
		count3[1][i] = count3[0][i-1] + count3[1][i-1];
		count4[1][i] = count4[0][i-1] + count4[1][i-1];
	}
 
	for (long i=0; i<N; i++) {
		b[count1[1][a[i] & 0x000000FFU]++] = a[i];
	}

	for (long i=0; i<N; i++) {
		a[count2[1][(b[i] >> 8) & 0x000000FFU]++] = b[i];
	}

	for (long i=0; i<N; i++) {
		b[count3[1][(a[i] >> 16) & 0x000000FFU]++] = a[i];
	}

	for (long i=0; i<N; i++) {
		if ((count4[1][b[i] >> 24]++) % 2 == 0) sum+= b[i];
	}	
	sum = sum%L;
	cout << sum;
	return 0;
}