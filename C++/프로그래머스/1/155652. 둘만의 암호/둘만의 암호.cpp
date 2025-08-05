#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

string solution(string s, string skip, int index)
{
    string answer = "";
    unordered_set<char> skip_set(skip.begin(), skip.end());

    for (char c : s) 
    {
        int cnt = 0;
        char cur = c;

        while (cnt < index) 
        {
            cur++;
            if (cur > 'z') cur = 'a'; // 알파벳 순환
            // set에 값이 존재하지 않으면 iterator가 end()까지 증가
            if (skip_set.find(cur) != skip_set.end()) continue; 
            cnt++;
        }
        answer.push_back(cur);
    }
    return answer;
}
