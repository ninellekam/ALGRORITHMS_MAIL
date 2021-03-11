#include <iostream>
#include <math.h>
#include <stdio.h>
#include <algorithm>

#define MAXN 500000

using namespace std;


struct pt {
	double x, y, id;
};

pt	a[MAXN];

inline bool cmp_x (const pt & a, const pt & b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

inline bool cmp_y (const pt & a, const pt & b) {
	return a.y < b.y;
}

double mindist;
int	ansa, ansb;

inline void upd_ans (const pt & a, const pt & b) {
	double dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + .0);
	if (dist < mindist || (dist == mindist && ansa > min(a.id, b.id)) ||
		(dist == mindist && ansa == min(a.id, b.id) && ansb > max(a.id, b.id) ) ) {
		mindist = dist;
		ansa = min(a.id, b.id);
		ansb = max(a.id, b.id);
	}
}

void rec (int l, int r) {
	if (r - l <= 3) {
		for (int i = l; i <= r; ++i)
			for (int j = i + 1; j <= r; ++j)
				upd_ans(a[i], a[j]);
		sort (a + l, a + r + 1, &cmp_y);
		return;
	}

	int m = (l + r) >> 1;
	double midx = a[m].x;
	rec (l, m),  rec (m+1, r);
	static pt t[MAXN];
	merge (a + l, a + m + 1, a + m + 1, a + r + 1, t, &cmp_y);
	copy (t, t + r - l + 1, a + l);

	int tsz = 0;
	for (int i = l; i <= r; ++i)
		if (abs (a[i].x - midx) < mindist) {
			for (int j = tsz - 1; j >= 0 && a[i].y - t[j].y < mindist; --j)
				upd_ans (a[i], t[j]);
			t[tsz++] = a[i];
		}
}

int main() {

	double x, y;
	unsigned long long N;
	cin >> N;
	for (unsigned long long i = 0; i < N; i++) {
		cin >> x >> y;
		a[i].x = x;
		a[i].id = i + 1;
		a[i].y = y;
	}
	sort (a, a + N, &cmp_x);
	mindist = 1E20;
	rec (0, N - 1);
	printf("%.10F", mindist);
	printf(" ");
	printf("%d", ansa);
	printf(" ");
	printf("%d", ansb);
}