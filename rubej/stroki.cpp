
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int len (int n) {
	if (n ==1) return 1;
	if (n >= 10) return 2 + 2 * len(n - 1);
	return 1 + 2 * len(n - 1);
}
int len_nina (int n) {
	if (n ==1) return 1;
	if (n >= 10) return (1 << (n))  ;
	return (1 << (n)) - 1 ;
}
int f(unsigned n, unsigned i) {
    int len_tmp = len (n);
	if (n >= 10) {
		if (i == 1) return n / 10; // в 1 строке
		if (i == 2) return n % 10; // во 2 строке
		i = i - 2;
		if (i > (len_tmp - 2) / 2) { // в 3 строке
			i = i - (len_tmp - 2) / 2;
			i = (len_tmp - 2) / 2 - i + 1;
		}
	}
    else {
		if (i == 1) return n;
		i = i - 1;
		if (i > (len_tmp - 1) / 2) {
			i = i - (len_tmp - 1) / 2;
			i = (len_tmp - 1) / 2 - i + 1;
		}
	}		
	return f(n - 1, i);
}

int main () {
	std:: cout << len(3) << " " << len(10) << std::endl ;
	std:: cout << len_nina(3) << " " << len_nina(10) << " " ;
	// int n, m, i, a;
	// scanf ("%d%d", &n, &m);
	// for (i = 0; i < m; i++) {
	// 	scanf ("%d", &a);
	// 	printf ("%d", f(n, a));
	// }
	// return (0);
}