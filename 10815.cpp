#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
   
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    
    cin >> m;
 
    for(int i=0; i<m; i++){
        int ans = 0;
        int a;
        cin >> a;
        int first = 0;
        int end = n-1;
        while(first <= end){
            int mid = (first + end) /2;
            if(v[mid] == a) {
                ans = 1;
                break;
              
            } else if(v[mid] < a) {
                first = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        cout << ans << ' ';
    }
    
    
    return 0;
}
