#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;


vector<int> v[10001];
vector<int> ans;
int cnt[10001];
int check[10001];
int tmp[10001];
int func(int num) {
    if (check[num] == 1) {
        return 0;
    }
    check[num] = 1;
    for (int i = 0; i < v[num].size(); i++) {
        int there = v[num][i];

        tmp[num] += func(there);
    }
    return tmp[num] + 1;
}
int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        memset(check, 0, sizeof(check));
        memset(tmp, 0, sizeof(tmp));

        cnt[i] = func(i);
    }
    int MAX = cnt[1];
    ans.push_back(1);


    for (int i = 2; i <= n; i++)
    {
        if (cnt[i] > MAX)
        {
            ans.clear();
            MAX = cnt[i];

            ans.push_back(i);
        }
        else if (cnt[i] == MAX)
            ans.push_back(i);
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }

    return 0;
}
