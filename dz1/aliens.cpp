#include <iostream>

using namespace std;

long long GCD(long long a,long long b) {
	long long shift;
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	for (shift = 0; ((a | b) & 1) == 0; ++shift) {
		a >>= 1;
		b >>= 1;
	}
	while ((a & 1) == 0)
		a >>= 1;
	do {
		while ((b & 1) == 0)
			b >>= 1;
		if (a > b) {
			long long t = b;
			b = a;
			a = t;
		}
		b = b - a;
	} while (b != 0);
	return a << shift;
}
int main()
{
	char ch_n[40];
	char *end;
	long long n = 0, cur_GCD = 0, sum = 0, prev, now;
	fgets(ch_n, 10, stdin);
	n = strtol(ch_n, &end, 10);
	fgets(ch_n, 30, stdin);
	prev = strtol(ch_n, &end, 10);
	for (int i = 0; i < n - 1; i++) {
		fgets(ch_n, 30, stdin);
		now = strtol(ch_n, &end, 10);
		if (GCD(prev, now) != 1) {
			sum += 1;
		}
		prev = now;
	}
	printf("%lld", sum);
}