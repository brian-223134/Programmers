#include <string>
#include <vector>

using namespace std;

// 상하좌우
int dh[4] = {-1,1,0,0};
int dw[4] = {0,0,-1,1};

bool OOB(int cur_h, int cur_w, int h, int w)
{
    return cur_h < 0 || cur_w < 0 || cur_h >= h || cur_w >= w;
}

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int board_h = board.size();
    int board_w = board[0].size();
    string cur_color = board[h][w];
    
    for (int i = 0; i < 4; i++)
    {
        int nh = h + dh[i];
        int nw = w + dw[i];
        if (OOB(nh,nw,board_h,board_w)) continue;
        if (board[nh][nw] == cur_color) answer++;
    }
    
    return answer;
}