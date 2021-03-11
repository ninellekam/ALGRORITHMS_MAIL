#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int>    mass,
                    power;

    int n, m ,p;
    cin >> n;
    for (int i = 0; i<n ; i++) {
        cin >> m >> p;
        mass.push_back(m);
        power.push_back(p);
    }
    sort(mass.begin(), mass.end());
    sort(power.begin(), power.end());
    long curMass = 0,
         curHeight = 0;
    
    for(int i = 0; i < mass.size(); i++) {
        if(power[i] >= curMass) {
            curMass += mass[i];
            curHeight++;
        }
    }
    cout << curHeight;

    return 0;
}