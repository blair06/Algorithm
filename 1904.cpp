#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{   
    int n;
    cin >> n;
    vector<int> v(n+1, 0);
    v[1] = 1;
    v[2] = 2;
    for (int i = 3; i <= n; i++) {
        v[i] = (v[i - 1] + v[i - 2])%15746;
        
    }
    cout << v[n] <<endl;


    return 0;
}
