#include <string>
#include <vector>
using namespace std;

int solution(int n) 
{
    const int MOD = 1000000007;
    if (n % 2 == 1) return 0; // 홀수면 불가능
    
    vector<long long> dp(n+1, 0);
    dp[0] = 1; dp[2] = 3;
    
    for (int i = 4; i <= n; i += 2) 
    {
        dp[i] = (dp[i-2] * 3) % MOD;
        for (int j = i-4; j >= 0; j -= 2) 
        {
            dp[i] = (dp[i] + (dp[j] * 2) % MOD) % MOD;
        }
    }
    return dp[n];
}