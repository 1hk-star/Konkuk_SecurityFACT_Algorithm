#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    // data 세팅
    vector<int> answer;
    int p1[5] = {1,2,3,4,5};
    int p2[8] = {2,1,2,3,2,4,2,5};
    int p3[10] = {3,3,1,1,2,2,4,4,5,5};
    int score[3] = {0,0,0};

    // 채점하기
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==p1[i%5])
            score[0]++;
        if(answers[i]==p2[i%8])
            score[1]++;
        if(answers[i]==p3[i%10])
            score[2]++;
    }
    
    // 최고점수 찾기
    int max=0;
    for(int i=0; i<3; i++){
        max = max > score[i] ? max : score[i];
    }
    
    // 가장 높은점수 받은 사람 출력
    for(int i=0; i<3; i++){
        if(max==score[i])
            answer.push_back(i+1);
    }
    return answer;
}