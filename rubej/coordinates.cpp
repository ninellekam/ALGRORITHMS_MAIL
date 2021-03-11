#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
    int n, count = 0;
    double a;
    scanf("%d", &n);
    vector <double> vec;
    for(int i = 0; i < n; i++) {
        scanf("%lf", &a);
        vec.push_back(a);
    }
    std::sort(vec.begin(),  vec.end());
    double x = vec[0] - 2; 
    for(int i = 0; i < n; i++)
    {
        if(x + 1 < vec[i]) 
        {
            x = vec[i];
            count++;
        }
    }
    printf("%d", count);
    return 0;
}