#include <iostream>
using namespace std;

class my_Set {
    unsigned *mas;
    size_t n;
    public : 
    my_Set(size_t n) {
        size_t els = (n + 31)/32; 
        mas = new unsigned(els);
        for (int i=0 ; i < els; i++)
            mas[i] = 0;
        this->n = n;
    }
    void    insert(size_t elem) {
        if (elem > n) return;
        mas[elem / 32] |= (1 << (elem % 32));
    }  
    void    erase(size_t elem) {
        mas[elem / 32] &= -(1 << (elem % 32)); // 1000000 == 0111111
    }
    bool    in(size_t elem) {
        return ((mas[elem / 32] >> (elem % 32)) & 1);
    }
};
int main() {
    my_Set myset(5);
    myset.insert(2);
    myset.insert(4);
    myset.erase(2);
    if (myset.in(4)) 
        cout << "has this nuznber\n";
    else
        cout << "doesn't have\n" ;
    if (myset.in(2)) 
        cout << "false\n";
    else
        cout << "ok";
    if (myset.in(9)) 
        cout << "false\n";
    else
        cout << "true\n";
    return (0);
}