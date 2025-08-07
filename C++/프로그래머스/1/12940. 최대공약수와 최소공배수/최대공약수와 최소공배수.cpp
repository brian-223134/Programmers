#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b, int g)
{
    return a / g * b;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int r = gcd(n,m);
    answer.push_back(r);
    answer.push_back(lcm(n,m,r));
    return answer;
}