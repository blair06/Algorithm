#include <iostream>
#include <algorithm>
#include <string.h>
#include <bitset>
using namespace std;

int n, m;
int arr[10000];
//long long alphabet = 11111111111111111111111111;
int alphabet =0;
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n >> m;
    //알파벳판
    for (int i = 0; i < 26; i++){
        alphabet |= (1 << i);
    }
    //단어를 비트마스킹함
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
      
        for(int j=0; j<str.size(); j++){
            int num;
            num = str[j] - 'a';
            
            arr[i] |= (1 << num);
            
        }

    }
    
    for(int i=0; i<m; i++){
        int cnt =0;
        int num;
        char alpha;
        cin >> num >> alpha;
        int alphaNum = alpha - 'a';
        if(num == 1){
            // 알파벳 잊기
            alphabet ^= (1<<alphaNum);
        }else{
            // 알파벳 기억하기
            alphabet |= (1<<alphaNum);
        }
        for(int j=0; j<n; j++){
            
            // 원래 단어 알파벳 보유 확인
            if((arr[j] & alphabet) == arr[j]){
                cnt++;
            }
        }
        
        cout << cnt << endl;
        
    }
    
}
