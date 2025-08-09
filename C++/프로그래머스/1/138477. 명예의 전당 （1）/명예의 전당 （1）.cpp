#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score)
{
    vector<int> answer;
    vector<int> temp; // 명예의 전당에 등록될 점수 후보군
    
    for (int i = 0; i < score.size(); i++)
    {
        temp.push_back(score[i]);
        sort(temp.begin(), temp.end(), [](int a, int b){return a > b;});
        int min_index;
        if (temp.size() <= k) min_index = temp.size();
        else min_index = k;
        answer.push_back(temp[min_index - 1]);
    }
    
    return answer;
}