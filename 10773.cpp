#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> v;
int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            v.pop_back();
        }
        else {
            v.push_back(a);
        }
        
    }
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    cout << sum;
    return 0;
}
