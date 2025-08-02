#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int option_select(const string &sort_by)
{
    if (sort_by == "code") return 0;
    else if (sort_by == "date") return 1;
    else if (sort_by == "maximum") return 2;
    else if (sort_by == "remain") return 3;
    else return -1; // 잘못된 입력 처리
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    // 어떤 것을 기준으로 정렬할 것인지 index 추출
    int option_sort = option_select(sort_by);
    int option_check = option_select(ext);
    
    sort(data.begin(), data.end(), [option_sort](const vector<int> &a, const vector<int> &b) {
             return a[option_sort] < b[option_sort];
         });
    
    for (auto &row: data)
    {
        // 추가할 정보 set
        if (row[option_check] < val_ext)
        {
            answer.push_back(row);
        }
    }
    
    return answer;
}