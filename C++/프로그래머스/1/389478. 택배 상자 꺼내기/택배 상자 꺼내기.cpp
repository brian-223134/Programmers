#include <vector>
#include <algorithm>

using namespace std;

vector<int> store;

int solution(int n, int w, int num) {
    int answer = 0;
    
    for(int i = 1; i<w*2; i+=2){
        store.push_back(i);
    }
    
    sort(store.rbegin(), store.rend());
    
    int floor = num/w - (num%w==0?1:0);
    
    int nextNum=num;
    while(nextNum<=n){
        int addNum;
        addNum = nextNum%w==0?w:nextNum%w;
        nextNum = nextNum+store[addNum-1];
        answer++;
        floor++;
    }
    
    return answer;
}