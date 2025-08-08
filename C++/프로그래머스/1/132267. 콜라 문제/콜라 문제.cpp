#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) 
{
    int answer = 0;
    
    // 빈 병의 개수(n)가 a개 이상일 때만 콜라를 교환할 수 있다.
    while (n >= a) 
    {
        // 교환해서 받을 수 있는 콜라의 개수를 계산한다.
        int new_cola = (n / a) * b;
        
        // 새로 받은 콜라의 개수를 정답에 더한다.
        answer += new_cola;
        
        // 다음 루프를 위해 남은 빈 병의 개수를 계산한다.
        // (현재 가지고 있던 빈 병을 a로 나눈 나머지) + (새로 받은 콜라의 수)
        n = (n % a) + new_cola;
    }
    
    return answer;
}