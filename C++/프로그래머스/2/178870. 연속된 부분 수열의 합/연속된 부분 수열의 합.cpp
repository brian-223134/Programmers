#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) 
{
    int n = sequence.size();
    int left = 0, right = 0;
    int sum = sequence[0];

    int bestLen = 1e9;
    vector<int> answer(2);

    while (left < n && right < n) 
    {
        if (sum == k) 
        {
            if (right - left < bestLen) 
            { 
                bestLen = right - left;
                answer = {left, right};
            }
            sum -= sequence[left++];
        }
        else if (sum < k) 
        {
            right++;
            if (right < n) sum += sequence[right];
        }
        else { // sum > k
            sum -= sequence[left++];
        }
    }
    return answer;
}