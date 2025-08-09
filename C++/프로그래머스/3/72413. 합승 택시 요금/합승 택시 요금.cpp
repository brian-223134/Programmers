#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    s--; a--; b--; // 배열 인덱스를 0부터 시작하도록 조정

    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) 
    {
        dist[i][i] = 0;
    }

    for (const auto& fare : fares) 
    {
        int u = fare[0] - 1;
        int v = fare[1] - 1;
        int cost = fare[2];
        dist[u][v] = cost;
        dist[v][u] = cost;
    }

    // 플로이드-워셜
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 최소 합승 요금 계산
    long long min_fare = 1e18;

    for (int k = 0; k < n; k++)
    {
        // k 지점까지 합승 후 각자 가는 경우의 총 비용
        long long current_fare = (long long)dist[s][k] + dist[k][a] + dist[k][b];
        min_fare = min(min_fare, current_fare);
    }
    
    return min_fare;
}