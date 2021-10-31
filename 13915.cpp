#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

int n;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin>>n){
        vector<int> arr;
        int cnt =0;
        for(int i=0; i<n; i++){
            int temp = 0;
            string str;
            cin >> str;
            
            // 개인 숙련도 비트마스킹
            for(int j=0; j<str.size(); j++){
                temp |= (1 << (str[j]-'0'));
            }
            // 같은 숙련도 종류가 있는지 판별
            bool isSame = false;
            for(int k=0; k<arr.size();k++){
                if(temp == arr[k]){
                    isSame = true;
                }
            }
            if(!isSame){
                arr.push_back(temp);
                cnt++;
            }

        }
        
        cout << arr.size() << endl;
    }
    
    return 0;
}
