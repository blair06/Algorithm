#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    long long s;
    cin >> n >> s;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    int st = 1;
    int end = 1;
    int total = v[1];
    //정답배열 길이
    int ans=987654321;
    while(st <= end && end <= n){
        if(total>=s){
            ans = min(ans,(end-st+1));
            total -= v[st];
            st++;
        }else if (total <s) {
            end++;
            total += v[end];
        }
    }
    if(ans == 987654321) {
        cout << "0";
        
    }else{
        cout << ans;
    }

    return 0;
    
}
