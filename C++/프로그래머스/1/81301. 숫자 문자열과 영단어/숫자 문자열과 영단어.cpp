#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool is_num(char c)
{
    return c >= '0' && c <= '9';
}

int solution(string s) 
{
    int answer = 0;
    unordered_map<string, char> table = {{"zero", '0'}, {"one", '1'}, {"two", '2'},
                                         {"three", '3'}, {"four", '4'}, {"five", '5'},
                                         {"six", '6'}, {"seven", '7'}, {"eight", '8'},
                                         {"nine", '9'}};
    string num = "";
    for (int i = 0; i < s.length(); i++)
    {
        if(is_num(s[i]))
        {
            num += s[i];
        }
        else
        {
            string temp = "";
            while(!is_num(s[i]))
            {
                temp += s[i];
                auto it = table.find(temp);
                if (it != table.end())
                {
                    break;
                }
                i++;
            }
            num += table[temp];
        }
    }
    return answer = stoi(num);
}