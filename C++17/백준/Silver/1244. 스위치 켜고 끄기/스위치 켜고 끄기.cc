#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cstring>

using namespace std;

int toggle(int x) { return 1 - x; } // 0<->1

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    int stu_num;
    cin >> stu_num;
    while (stu_num--)
    {
        int gender, num;
        cin >> gender >> num;

        if (gender == 1) 
        {
            // 남학생: 배수 토글
            for (int k = num; k <= n; k += num) arr[k] ^= 1; // xor로 깔끔히
        }
        else {
            // 여학생: 중심 먼저 토글 후 좌우 대칭 확장
            int left = num, right = num;
            // 중심 포함해서 확장 가능한 최대 구간 찾기
            while (left - 1 >= 1 && right + 1 <= n && arr[left - 1] == arr[right + 1]) 
            {
                --left; ++right;
            }
            // [left, right] 모두 토글
            for (int i = left; i <= right; ++i) arr[i] ^= 1;
        }
    }

    for (int i = 1; i <= n; ++i) 
    {
        cout << arr[i] << ' ';
        if (i % 20 == 0) cout << '\n';
    }
    if (n % 20 != 0) cout << '\n';
    return 0;
}