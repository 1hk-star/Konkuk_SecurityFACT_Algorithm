#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    //Ʈ���� ����, ���� �ٸ��� ��
    map<int, int> waiting;
    int time=0;
    //���� ���� �ִ� Ʈ���� ������ ��
    int total = 0;
    while(truck_weights.size() !=0) {
        time+=1;
        //waiting�� bridge_length���� ���� ��쿡�� �߰� ����
        if(waiting.size() <= bridge_length) {
            //���� ���� �ִ� Ʈ���� ������ �հ� ���� ���� Ʈ���� ������ ���� weight ���� ���� ��츸 �߰� ����
            if(total+truck_weights<=weight) {

            }

        }
    }
    return answer;
}

int main(void) {

} 
