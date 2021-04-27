#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 

int n,k;
int check;
int word[50];

int func(int s, int learn){
    int cnt = 0;
    //k개를 다 배운경우
    if(learn == k){
        for(int i=0; i<n; i++){
            //배운 알파벳으로 단어를 만들수 있는 경우 증가
            if((check & word[i]) == word[i]){
                cnt++;
            }
        }
        return cnt;
    }
    
    for(int i=s; i<26; i++ ){
        if((check & (1 << i)) == 0){
            check |= (1 << i);
            cnt = max(cnt, func(i + 1, learn+ 1));
            check &= ~(1<<i);
        }
            
    }

    return cnt;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    if(k<5){
        cout << 0;
        return 0;
    } else if(k == 26){
        cout << n;
        return 0;
    }
    check |= 1<<('a'-'a');
    check |= 1<<('n'-'a');
    check |= 1<<('t'-'a');
    check |= 1<<('i'-'a');
    check |= 1<<('c'-'a');
    
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        word[i] = check;
        for(int j=4; j<str.size()-4; j++){
            word[i] |= (1 << (str[j] - 'a'));
        }
    }

    cout << func(0,5);
    return 0;
}
