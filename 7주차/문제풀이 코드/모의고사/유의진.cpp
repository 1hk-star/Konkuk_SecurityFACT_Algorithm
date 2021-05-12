#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> ans1={1,2,3,4,5};
    vector<int> ans2={2,1,2,3,2,4,2,5};
    vector<int> ans3={3,3,1,1,2,2,4,4,5,5};
    int cnt1=0, cnt2=0, cnt3=0;
    for(int j=0; j<answers.size(); j++){
        if(answers[j]==ans1[j%5])    cnt1++;
    }
    for(int j=0; j<answers.size(); j++){
        if(answers[j]==ans2[j%8])    cnt2++;
    }
    for(int j=0; j<answers.size(); j++){
        if(answers[j]==ans3[j%10])   cnt3++;
    }
    if(cnt1==cnt2){
        answer.push_back(1);
        answer.push_back(2);
    }
    else    answer.push_back(cnt1>cnt2?1:2);
    int max=cnt1>=cnt2?cnt1:cnt2;
    if(max==cnt3) answer.push_back(3);
    else if(max<cnt3){
        answer.clear();
        answer.push_back(3);
    }
    return answer;
}
