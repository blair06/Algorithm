#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

int n, m, k;
int main()
{
    cin >> n >> m >> k;
    int round = 1;
    while (1) {
        if ((!(m % 2) && k == m - 1) || (!(k % 2) && m == k - 1)) break;
        else {
            if (m % 2) { 
                m = (m + 1) / 2; 
            }
            else { m = m / 2; }

            if (k % 2) {
                k = (k + 1) / 2;
            }
            else { k = k / 2; }
        }
        round++;
    }

    cout << round;
    return 0;
}
