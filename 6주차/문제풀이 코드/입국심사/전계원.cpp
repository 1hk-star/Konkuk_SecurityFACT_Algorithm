#include <string>
#include <vector>

using namespace std;
long long solution(int n, vector<int> times) {
    long long answer=1000000000000000000;
    long long low=1, high=1000000000000000000;
    
    while(low<=high){
        long long mid = (low+high)/2;
        long long count=0;
        for(long long i=0; i<times.size(); i++){
            count += mid/times[i];
        }
        if(count >= n){
            // 성공
            answer = answer < mid ? answer : mid;
            high = mid-1;
        } else {
            // 실패
            low = mid+1;
        }
    }
    
    return answer;
}