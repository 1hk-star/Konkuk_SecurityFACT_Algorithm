#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int count = 0;
    //h번 이상 인용된 h개의 논문이 있으면 h를 리턴
    sort(citations.begin(),citations.end(),greater<int>());
    //6 5 3 1 0
    
    for(int i=citations[0];i>=0;i--){ //i=6 5 4 3 2 1 0
        count = 0;
        for(int j=0;j<citations.size();j++){ //j=0 1 2 3 4
            if(i<=citations[j]){ //6 <= 6 5 3 1 0
                count++;
            }
        }
        if(count>=i)
            return i; //가장먼저 구해진게 최댓값임
    }
    
    return 0;
}