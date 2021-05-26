#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int check[40]={0, };
    answer=n-lost.size();
    for(int i=0; i<lost.size(); i++){
        check[lost[i]]--;
    }
    for(int i=0; i<reserve.size(); i++){
        check[reserve[i]]++;
        if(check[reserve[i]]==0){
            answer++;
            reserve[i]=0;
        }
    }
    for(int i=0; i<reserve.size(); i++){   
        int k=reserve[i];
        if(k!=0){
            if(check[k-1]==-1 || check[k+1]==-1){
                check[k]=0;
                answer++;
                check[k-1]==-1 ? check[k-1]=0 : check[k+1]=0;
            }
        }
    }
    return answer;
}
