#include <iostream>
#include <vector>
using namespace std;

long long getFibb(long long n, long long zn) {
    long long a11 = 1, a12 = 1, a21 = 1, a22 = 0; //матрица оператора
    long long r11 = 1, r12 = 0; //вектор-столбец результа
    long long q11 = 0, q12 = 0, q21 = 0, q22 = 0; //вспомогательная матрица при перемножении
    while (n > 0) {
        if ((n&1)==1) {
            q11 = (r11 * a11 + r12 * a21) % zn;
            q12 = (r11 * a12 + r12 * a22) % zn;
        r11 = q11;
        r12 = q12;
    }
    q11 = (a11 * a11 + a12 * a21) % zn;
    q12 = (a11 * a12 + a12 * a22) % zn;
    q21 = (a21 * a11 + a22 * a21) % zn;
    q22 = (a21 * a12 + a22 * a22) % zn;
    a11 = q11;
    a12 = q12;
    a21 = q21;
    a22 = q22;
    n >>= 1;
}
return r12; //возвращаем Fn
}

int main() {
    long long n, zn;
    cin >> n >> zn;
    cout << getFibb(n , zn);
    return (0);
}