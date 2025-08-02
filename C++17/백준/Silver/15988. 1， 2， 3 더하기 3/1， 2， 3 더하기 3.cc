#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;
long long dp[1000001];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[3] = 4;
    int mem = 4;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (dp[temp] != 0)
        {
            cout << dp[temp] % 1000000009 << '\n';
        }
        else
        {
            for (int j = mem; j <= temp; j++)
            {
                dp[j] = (dp[j - 1] + dp[j - 2] + dp[j - 3]) % 1000000009;
            }
            cout << dp[temp] << '\n';
            mem = temp + 1;
        }
    }

    return 0;
}