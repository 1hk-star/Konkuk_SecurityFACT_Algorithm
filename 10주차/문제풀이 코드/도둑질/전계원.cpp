#include <string>
#include <vector>
#include <iostream>

using namespace std;

int DP(vector<int> money){
    vector<int> DP; // i번째까지 훔쳤을 때 얻을 수 있는 최대값
    if(money.size()>=1){
        DP.push_back(money[0]);
    }
    if(money.size()>=2){
        int tmp = money[0] > money[1] ? money[0] : money[1];
        DP.push_back(tmp);
    }
    if(money.size()>=3){
        int tmp = money[0]+money[2] > money[1] ? money[0]+money[2] : money[1];
        DP.push_back(tmp);
    }
    for(int i=3; i<money.size(); i++){
        int tmp = money[i]+DP[i-2] > money[i]+DP[i-3] ? money[i]+DP[i-2] : money[i]+DP[i-3];
        DP.push_back(tmp);
    }
    
    // 최대값 구하기
    int max = 0;
    for(int i=0; i<DP.size(); i++){
        max = max > DP[i] ? max : DP[i];
    }
    return max;
}

int solution(vector<int> money) {
    int answer = 0;
    
    // case 1번
    vector<int> money1;
    for(int i=0; i<money.size()-1; i++){
        money1.push_back(money[i]);
    }
    int dp1 = DP(money1);
    
    // case 2번
    vector<int> money2;
    for(int i=1; i<money.size(); i++){
        money2.push_back(money[i]);
    }    
    int dp2 = DP(money2);

    // 정답출력
    answer = dp1 > dp2 ? dp1 : dp2;
    return answer;
}