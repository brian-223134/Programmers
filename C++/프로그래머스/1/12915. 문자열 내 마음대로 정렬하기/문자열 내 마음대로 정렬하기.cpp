#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    sort(strings.begin(), strings.end(), [n](const string& a, const string& b) {
        // 첫 번째 비교 기준: n번째 인덱스의 문자
        if (a[n] != b[n]) {
            return a[n] < b[n];
        }
        // n번째 인덱스의 문자가 같을 경우, 두 번째 비교 기준: 사전순 (전체 문자열)
        else {
            return a < b;
        }
    });

    return strings;
}