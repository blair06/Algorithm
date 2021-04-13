#include<stdio.h>
#include<iostream>
#include<math.h>

using namespace std;

int x, y;
int cnt=0;

void func(int a, int b, int c, int d, int vol) {
    if (vol==1) {
        if (a == x and b == y) {
            cout << cnt<<endl;
        }
        cnt++;
    }
    else {
        if(x< (a + c) / 2 and y< (b + d) / 2) {
            func(a, b, (a + c) / 2, (b + d) / 2, vol / 4);
        }
        else {
            cnt += vol / 4;
        }
        
        if (x < (a + c) / 2 and y >= (b + d) / 2){
            func(a, (b + d) / 2, (a + c) / 2, d, vol / 4);
        }
        else {
            cnt += vol / 4;
        }
        
        if (x >= (a + c) / 2 and y < (b + d) / 2){
            func((a + c) / 2, b, c, (b + d) / 2, vol / 4);
        }
        else {
            cnt += vol / 4;
        }
        
        if((a + c) / 2<=x and (b + d) / 2<=y){
            func((a + c) / 2, (b + d) / 2, c, d, vol / 4);
        }
        else {
            cnt += vol / 4;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n>>x>>y;
    
    func(0, 0, pow(2, n), pow(2, n), pow(4, n));
}
