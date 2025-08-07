#include <string>
#include <vector>

using namespace std;

bool visited[26];

vector<int> solution(string s) 
{
    vector<int> answer;
    
    visited[s[0] - 'a'] = true;
    answer.push_back(-1);
    
    for (int i = 1; i < s.length(); i++)
    {
        // 처음 보인 단어라면 -1을 push하고 visit 처리
        if (!visited[s[i] - 'a'])
        {
            answer.push_back(-1);
            visited[s[i] - 'a'] = true;
            continue;
        }
        int place = 1000000;
        for (int j = 0; j < i; j++)
        {
            if (s[i] == s[j]) place = min(i - j, place);
        }
        answer.push_back(place);
    }
    
    return answer;
}