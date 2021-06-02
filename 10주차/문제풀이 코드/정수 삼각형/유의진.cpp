#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n=triangle.size()-1;
    for(int i=n; i>=0; i--){
        for(int j=0; j<i; j++){
            triangle[i-1][j]+= (triangle[i][j]>triangle[i][j+1])?triangle[i][j]:triangle[i][j+1];
        }
    }
    return triangle[0][0];
}
