#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int cnt = 0;
        cin >> n;
        vector<int> v(n+1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j*i <= n; j++) {
                if (v[i * j] == 0) {
                    v[i * j] = 1;
                }
                else {
                    v[i * j] = 0;
                }
            }
            
        }
        for (int i = 1; i < v.size(); i++) {
            if (v[i] == 1) {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
