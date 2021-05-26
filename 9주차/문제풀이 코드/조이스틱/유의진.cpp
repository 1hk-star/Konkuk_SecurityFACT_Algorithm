#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0, i=1;
    int now=0;  //현재 커서 위치
    bool check[21]={false, };
    int t=name.length();   //설정해야 할 알파벳 개수
    int n=name.length();
    for(int i=0; i<n; i++){
        if(name[i]<'N') answer += ((int)name[i]-65);
        else    answer += (91-(int)name[i]);
        if(name[i]!='A')    check[i]=true;//설정 필요 표시
        else    t--;    //A는 설정 안해도 됨
    }
    while(t>0){
        if(check[now]==true){
            check[now]=false;
            t--;
            i=1;
        }
        if(check[now+i>=n ? now-n+i : now+i]){
            now= now+i>=n ? now-n+i : now+i;
            answer+=i;
        }
        else if(check[now-i<0 ? now+n-i : now-i]){
            now=now-i<0 ? now+n-i : now-i;
            answer+=i;
        }
        else    i++;
    }
    return answer;
}
