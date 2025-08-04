#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) 
{
    int answer = 0;
    int len = p.length();

    for (int i = 0; i <= t.length() - len; i++)
    {
        string sub = t.substr(i, len);
        if (sub <= p) answer++;
    }
    
    return answer;
}