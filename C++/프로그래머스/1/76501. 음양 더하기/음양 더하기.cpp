#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    unordered_map<bool, int> table = {{false, -1}, {true, 1}};
    for (int i = 0; i < absolutes.size(); i++)
    {
        answer += absolutes[i] * table[signs[i]];
    }
    return answer;
}