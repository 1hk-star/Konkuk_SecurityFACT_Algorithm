#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int n;
    sort(people.begin(), people.end(), greater<int>());   //내림차순 정렬
    n=people.size();
    for(int i=0; i<n; i++){
        if(people[i]+people[n-1]<=limit && n!=1){
            n--;    //가장 가벼운 사람 탑승
        }
        answer++;
    }
    return answer;
}


