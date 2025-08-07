#include <string>
#include <vector>

using namespace std;

bool is_num(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] - '0' < 0 || s[i] - '0' > 9) return false;
    }
    return true;
}

bool solution(string s) {
    bool answer = true;
    if (s.length() != 4 && s.length() != 6) return false;
    if (is_num(s)) return true;
    return false;
}