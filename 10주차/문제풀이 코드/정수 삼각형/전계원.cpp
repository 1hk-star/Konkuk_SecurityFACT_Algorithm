#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> DP;

    // 첫 번째 원소 넣어주기
    vector<int> tmp_vec;
    tmp_vec.push_back(triangle[0][0]);
    DP.push_back(tmp_vec);

    // 두 번째 원소부터 넣어주기
    for(int i=1; i<triangle.size(); i++){
        vector<int> tmp_vec;
        for(int j=0; j<triangle[i].size(); j++){
            if(j==0){
                // 첫 원소
                tmp_vec.push_back(triangle[i][j]+DP[i-1][j]);
            } else if(j==triangle[i].size()-1){
                // 끝 원소                
                tmp_vec.push_back(triangle[i][j]+DP[i-1][j-1]);
            } else {
                // 중간 원소
                int tmp = DP[i-1][j] > DP[i-1][j-1] ? DP[i-1][j] : DP[i-1][j-1];
                tmp_vec.push_back(triangle[i][j] + tmp);
            }
        }
        DP.push_back(tmp_vec);
    }

    // 맨 아랫줄 에서 가장 큰 값 찾기
    for(int i=0; i<DP[DP.size()-1].size(); i++){
        answer = answer > DP[DP.size()-1][i] ? answer : DP[DP.size()-1][i];
    }
    return answer;
}