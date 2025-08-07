#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) {
    if (arr.size() == 1)
        return {-1};

    // 가장 작은 값 찾기
    int min_val = *min_element(arr.begin(), arr.end());

    // 해당 값 제거 (첫 번째 등장만 제거하려면 remove 사용 x)
    vector<int> result;
    for (int x : arr) {
        if (x != min_val)
            result.push_back(x);
    }

    return result;
}
