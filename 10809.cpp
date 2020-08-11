#include <iostream> 
#include <string.h> 
using namespace std;
int main() {
    string s;
    cin >> s;
    int n;
    for (char a = 'a'; a <= 'z'; a++) {
        n = s.find(a); cout << n << " "; 
    } 
}
