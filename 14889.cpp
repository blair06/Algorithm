#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int used[21] = { 0, };
vector<int> start;
vector<int> link;
int v[21][21];

int s_power = 0;
int l_power = 0;
int result = 1000000;

void func(int curr_player, int cnt) {

    if (cnt == n / 2) {
        start.clear();
        link.clear();
        s_power = 0;
        l_power = 0;
        for (int i = 0; i < n; i++) {
            if (used[i]==1) {
                start.push_back(i);
            }
            else {
                link.push_back(i);
            }
        }
       
        for (int i = 0; i < n/2; i++) {
            for (int k = 0; k <n/2; k++) {
               s_power += v[start[i]][start[k]] ;
               l_power += v[link[i]][link[k]];
            }
        }

        result = min(result, abs(s_power- l_power));
        
    }

    for (int i = curr_player ; i < n; i++)
    {
        if (used[i] == 0)
        {
            used[i] = 1;
            func(i, cnt + 1);
            used[i] = 0;
        }
    }

}
int main(void) {
    cin >> n;


    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            cin >> v[i][k];
        }
    }
    func(0,0);
    cout << result;
    return 0;
}
