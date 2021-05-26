#include <string>
#include <vector>

using namespace std;

bool prime_table[10000000];
int cnt=0;
void recursive_search(vector<pair<int, int>> v, int depth, string str, int cur_depth){
    if(depth==cur_depth){
        // 끝까지 도달 완료
        if(str[0]!='0' && prime_table[stoi(str)]){
            cnt++;
        }
    } else {
        // 아직 도달하지 않음
        for(int i=0; i<v.size(); i++){
            // i번째 숫자를 1개 제외한 나머지 vector 만들기
            vector<pair<int, int>> v_cpy;
            for(int j=0; j<v.size(); j++){
                if(i==j && v[j].second>1){
                    v_cpy.push_back(make_pair(v[j].first, v[j].second-1));
                } else if(i!=j) {
                    v_cpy.push_back(make_pair(v[j].first, v[j].second));
                }
            }

            // 재귀
            recursive_search(v_cpy, depth, str+to_string(v[i].first), cur_depth+1);
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    // 소수 테이블을 만들기
    for(long i=0; i<10000000; i++){
        prime_table[i]=true;
    }
    prime_table[0]=false; prime_table[1]=false;
    for(long i=2; i<10000000; i++){
        if(prime_table[i]==true){
            for(long j=i+i; j<10000000; j+=i){
                prime_table[j]=false;
            }
        }
    }
    
    // 완전탐색 위한 사전준비
    char num_count[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0; i<numbers.length(); i++){
        num_count[numbers[i]-'0']++;
    }
    vector<pair<int, int>> v; // number, cnt
    for(int i=0; i<10; i++){
        if(num_count[i]!=0){
            v.push_back(make_pair(i, num_count[i]));
        }
    }
    
    // 재귀로 모든 깊이 완전탐색
    for(int i=1; i<=numbers.length(); i++){
        recursive_search(v, i, "", 0);
    }

    answer = cnt;
    return answer;
}