#include <string>
#include <vector>

using namespace std;

int solution(int num) 
{
    long long n = num;
    int answer = 0, cnt = 0;
    while(cnt <= 500)
    {
        if (n == 1) break;
        if (n % 2 == 0)
        {
            n /= 2;
            cnt++;
        }
        else
        {
            n *= 3;
            n++;
            cnt++;
        }
    }
    return answer = cnt > 500 ? -1 : cnt;
}