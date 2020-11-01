#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a,b,v;
int cnt = -1;
int main() {
    cin >> a >> b >> v;
    cout << (v - b-1 )/(a-b)+1;
    
    return 0;
}
