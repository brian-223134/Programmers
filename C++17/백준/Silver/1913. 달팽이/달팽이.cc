#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X;
    cin >> N >> X;

    vector<vector<int>> board(N, vector<int>(N, 0));

    // 방향: 위, 오른쪽, 아래, 왼쪽
    int dr[4] = { -1, 0, 1, 0 };
    int dc[4] = { 0, 1, 0, -1 };

    int r = N / 2, c = N / 2; // 중앙 시작
    int num = 1;
    board[r][c] = num;

    int target_r = r, target_c = c;
    if (X == 1) {
        target_r = r;
        target_c = c;
    }

    int step = 1;
    int dir = 0;

    while (num < N * N) {
        for (int k = 0; k < 2; k++) {
            for (int i = 0; i < step; i++) {
                r += dr[dir];
                c += dc[dir];

                num++;
                board[r][c] = num;

                if (num == X) {
                    target_r = r;
                    target_c = c;
                }
                if (num == N * N) break;
            }
            if (num == N * N) break;
            dir = (dir + 1) % 4;
        }
        step++;
    }

    // 배열 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    // X의 좌표 출력
    cout << target_r + 1 << " " << target_c + 1 << "\n";

    return 0;
}
