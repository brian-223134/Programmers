#include <string>
#include <vector>
#include <bitset>
#include <algorithm> // for std::replace

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < arr1.size(); i++) {
        // arr1[i]와 arr2[i]를 비트 OR 연산
        int combined = arr1[i] | arr2[i];
        
        // 이진수 변환 및 문자열로 포맷팅
        string binary_string = "";
        for (int j = n - 1; j >= 0; j--) {
            // combined의 j번째 비트가 1인지 확인
            if ((combined >> j) & 1) {
                binary_string += '#';
            } else {
                binary_string += ' '; // 공백으로 수정
            }
        }
        answer.push_back(binary_string);
    }
    return answer;
}