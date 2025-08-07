#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for (int i = left; i <= right; i++)
    {
        int temp = (int) sqrt(i);
        if(temp * temp == i) answer -= i;
        else answer += i;
    }
    return answer;
}