#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int n;
    sort(people.begin(), people.end(), greater<int>());   //�������� ����
    n=people.size();
    for(int i=0; i<n; i++){
        if(people[i]+people[n-1]<=limit && n!=1){
            n--;    //���� ������ ��� ž��
        }
        answer++;
    }
    return answer;
}


