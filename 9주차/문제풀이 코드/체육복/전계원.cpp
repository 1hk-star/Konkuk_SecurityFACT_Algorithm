#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> student;
    // 체육복 하나씩 다 주기
    for(int i=0; i<n; i++){
        student.push_back(1);
    }
    // 여벌의 체육복 제공
    for(int i=0; i<reserve.size(); i++){
        student[reserve[i]-1]++;
    }
    // 체육복 뺏기
    for(int i=0; i<lost.size(); i++){
        student[lost[i]-1]--;
    }
    // 앞에서부터 옷 빌릴 수 있는 애들 빌리기
    for(int i=0; i<n; i++){
        if(student[i]==0){
            if(i>0 && student[i-1]==2){
                student[i-1]--;
                student[i]++;
            } else if(i<n && student[i+1]==2){
                student[i+1]--;
                student[i]++;
            }
        }
    }
    // 그럼 체육복을 1개 이상 갖고 있는 친구들 개수 세기
    for(int i=0; i<n; i++){
        if(student[i]>=1)
            answer++;
    }
    return answer;
}