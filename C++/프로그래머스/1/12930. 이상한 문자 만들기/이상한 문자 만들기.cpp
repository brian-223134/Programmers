#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    int index = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            answer += ' ';
            index = 0;
            continue;
        }
        if (index%2 == 0) 
        {
            answer += toupper(s[i]);
            index++;
        }
        else
        {
            answer += tolower(s[i]);
            index++;
        }
    }
    
    return answer;
}