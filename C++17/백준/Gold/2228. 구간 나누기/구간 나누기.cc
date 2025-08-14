#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>
#include <climits>

using namespace std;
const int INF = -987654321; // 충분히 작은 값으로 초기화

int num[101];
int dp[101][101]; // dp[i][j]: i번째 숫자까지 j개의 구간을 만들었을 때의 최대 합
int sum[101];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }

    // 누적 합 계산
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + num[i];
    }

    // dp 배열 초기화
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = INF;

    // 0개의 구간은 합이 0
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            // i번째 숫자를 포함하지 않는 경우
            dp[i][j] = dp[i - 1][j];

            // i번째 숫자를 마지막 구간의 끝으로 포함하는 경우
            // k는 마지막 구간의 시작점
            for (int k = 1; k <= i; k++)
            {
                // k-1번째 숫자까지 j-1개의 구간을 만든 최대 합에
                // k부터 i까지의 합을 더한다.
                // (k-1)-1 = k-2번째 숫자까지 j-1개의 구간을 만든 최대 합을 찾아야 함
                // 단, k가 1일 때는 dp[0][j-1]을 사용해야 하므로 k-2가 아닌 k-1-1을 사용
                // k-1번째 숫자와 k번째 숫자는 인접하면 안되므로 k-1번째 숫자까지 만든
                // 합을 사용하고, k-1번째 숫자를 버리고 k번째 숫자부터 새로운 구간을 시작
                if (k >= 2 && dp[k - 2][j - 1] != INF)
                {
                    dp[i][j] = max(dp[i][j], dp[k - 2][j - 1] + (sum[i] - sum[k - 1]));
                }
                // 첫번째 구간인 경우 (j=1)
                else if (j == 1)
                {
                    dp[i][j] = max(dp[i][j], sum[i] - sum[k - 1]);
                }
            }
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}