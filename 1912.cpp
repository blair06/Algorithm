#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    int MAX;
    cin >> n;
    vector<int> v(n);
    vector<int> temp(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    temp[0] = v[0];
    MAX = temp[0];
    for (int i = 1; i < v.size(); i++) {
        temp[i] = max(v[i], temp[i - 1] + v[i]);
        MAX = max(temp[i], MAX);
    }
    cout << MAX;
    return 0;
}
