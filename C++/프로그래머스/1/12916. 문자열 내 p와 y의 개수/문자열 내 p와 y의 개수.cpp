#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p_num = 0, y_num = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'p' || s[i] == 'P') p_num++;
        if(s[i] == 'y' || s[i] == 'Y') y_num++;
    }

    return answer = p_num == y_num ? true : false;
}