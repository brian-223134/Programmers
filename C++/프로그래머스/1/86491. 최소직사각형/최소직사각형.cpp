#include <string>
#include <vector>
#include <algorithm> // max, min 함수를 위해 포함

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    int max_w = 0; // 모든 명함의 긴 쪽 길이 중 최댓값을 저장할 변수
    int max_h = 0; // 모든 명함의 짧은 쪽 길이 중 최댓값을 저장할 변수

    for (int i = 0; i < sizes.size(); i++) 
    {
        // 현재 명함의 가로, 세로 중 더 긴 쪽과 짧은 쪽을 구함
        int w = max(sizes[i][0], sizes[i][1]);
        int h = min(sizes[i][0], sizes[i][1]);

        // 전체 지갑의 가로, 세로 최댓값을 갱신
        max_w = max(max_w, w);
        max_h = max(max_h, h);
    }

    // 최종적으로 필요한 지갑의 넓이 반환
    return max_w * max_h;
}