#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int n;
int k;
int sum;
int main() {
    cin >> n >> k;
    int first = 1;
    int end = n;

 
        
    int low = 1, high = k;

    int result = -1;

    while (low <= high)

    {

        int cnt = 0;

        int mid = (low + high) / 2;

        for (int i = 1; i <= n; i++)

            cnt += min(mid / i, n);

        if (cnt < k)

            low = mid + 1;

        else

        {

            result = mid;

            high = mid - 1;

        }

    }

    cout << result << "\n";

    
    return 0;
}
