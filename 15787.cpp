#include <iostream>
#include <vector>
#include <set>
#include<algorithm>
#include <memory.h>
using namespace std;
 

int n,m;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> v(n+1,0);
    while(m--){
        int num, idx, seat;
        cin >> num;
        switch (num) {
            case 1:
                cin >> idx >> seat;
                v[idx] |= (1<<(seat-1));
                break;
            case 2:
                cin >> idx >> seat;
                v[idx] &= ~(1 << (seat - 1));
                break;
            case 3:
                cin >> idx;
                v[idx] = v[idx] << 1 ;
                v[idx] &= ((1 << 20) - 1);
                break;
            default:
                cin >> idx;
                v[idx] = v[idx] >> 1;
                break;
        }
    }
    set<int> s;
    for(int i=1; i<=n; i++){
        s.insert(v[i]);
    }
    cout << s.size();
    return 0;
}
