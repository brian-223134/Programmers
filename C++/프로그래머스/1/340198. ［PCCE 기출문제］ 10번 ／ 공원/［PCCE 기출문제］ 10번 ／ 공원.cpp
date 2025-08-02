#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    
    int test_case = mats.size(); // 벡터 크기만큼 테스트해보기
    sort(mats.begin(), mats.end(), greater<int>());
    
    for (int i = 0; i < test_case; i++)
    {
        bool find_flag = false;
        int mat_size = mats[i];
        if (park.size() < mat_size) continue;

        for (int a = 0; a <= park.size() - mat_size; a++)
        {
            if (park[a].size() < mat_size) continue;
            if(find_flag) break;
            for (int b = 0; b <= park[a].size() - mat_size; b++)
            {
                if(find_flag) break;
                int cnt = 0;
                for (int x = 0; x < mat_size; x++) 
                {
                    for (int y = 0; y < mat_size; y++) 
                    {
                        if (park[a + x][b + y] == "-1") cnt++;
                    }
                }
                if (cnt == mat_size * mat_size) 
                {
                    answer = mat_size;
                    find_flag = true;
                }
            }
        }
        if(find_flag) break;
    }
    
    if (answer == 0) answer = -1;
    return answer;
}