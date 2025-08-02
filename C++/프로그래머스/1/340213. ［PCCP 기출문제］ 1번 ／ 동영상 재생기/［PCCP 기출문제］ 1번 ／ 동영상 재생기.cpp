#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int _video_len, _pos, _op_start, _op_end;

bool IsOp(int pos) 
{
    if (_op_start <= pos && pos < _op_end) return true;
    else return false;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {

    _video_len = 60 * stoi(video_len.substr(0, 2)) + stoi(video_len.substr(3, 5));
    _pos = 60 * stoi(pos.substr(0, 2)) + stoi(pos.substr(3, 5));
    _op_start = 60 * stoi(op_start.substr(0, 2)) + stoi(op_start.substr(3, 5));
    _op_end = 60 * stoi(op_end.substr(0, 2)) + stoi(op_end.substr(3, 5));

    if (IsOp(_pos)) 
    {
        _pos = _op_end;
    }

    for(string& comm : commands) 
    {
        if (comm == "next") 
        {
            _pos = min(_video_len, _pos + 10);
            if (IsOp(_pos)) 
            {
                _pos = _op_end;
            }
        }
        else if (comm == "prev") 
        {
            _pos = max(0, _pos - 10);
            if (IsOp(_pos)) 
            {
                _pos = _op_end;
            }
        }
    }

    int tmp;
    tmp = _pos / 60;
    string mm = (tmp < 10 ? "0" : "") + to_string(tmp);
    tmp = _pos % 60;
    string ss = (tmp < 10 ? "0" : "") + to_string(tmp);
    string result = mm + ":" + ss;
    
    return result;
}