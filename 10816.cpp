#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(0);

            cin.tie(0);

    cin >> n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    cin >> m;
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        auto up = upper_bound(v.begin(), v.end(),a);
        auto lo = lower_bound(v.begin(), v.end(),a);
    
        cout << up - lo << ' ';

    }
}
