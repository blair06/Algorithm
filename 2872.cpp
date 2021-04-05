#include <iostream>
#include <vector>
int n;


using namespace std;
int main() {
    cin >> n;
    vector<int> v(n+1);
    for(int i=1; i<=n; i++){
        cin >> v[i];
    }
    int num =n;
    for(int i=n; i>0; i--){
        if(v[i] == num){
            num--;
        }
    }
    
    cout << num;
    return 0;
}
