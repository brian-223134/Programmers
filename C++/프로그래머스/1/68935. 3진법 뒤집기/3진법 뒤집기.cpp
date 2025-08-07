#include <string>
using namespace std;

int solution(int n) {
    string num = "";

    // 1. 3진수 변환 후 뒤집어서 저장
    do {
        num += to_string(n % 3);
        n /= 3;
    } while (n > 0);

    // 2. 뒤집힌 3진수 → 10진수로 변환
    long long answer = 0;
    long long digit = 1;

    for (int i = num.length() - 1; i >= 0; i--) {
        answer += digit * (num[i] - '0');
        digit *= 3;
    }

    return static_cast<int>(answer);
}
