#include<string>
#include<vector>

using namespace std;

bool used[10000000];
bool check[10];
int answer;

void dfs(int cnt, string numbers, string now){
    if(now!="" && !used[stoi(now)]){
        int num=stoi(now);
        used[num]=true;
        if(num>1){
            int c=0;
            for(int i=2;i*i <= num; i++){
                if(num%i==0){
                    c=-1;
                    break;
                }
            }
            if(c==0)    answer++;
        }
    }
    for(int i=0; i<numbers.length(); i++){
        if(check[i]==true)  continue;
        check[i]=true;
        dfs(cnt+1, numbers, now+numbers[i]);
        check[i]=false;
    }
}

int solution(string numbers){
    dfs(0, numbers, "");
    return answer;
}
