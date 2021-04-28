#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int max = 0;
    int count = 0;
    int size = citations.size();
    
    for(int i =0 ; i < size; i ++){
        if (max < citations[i]){
            for(int j = 0; j < size; j++){
                if(citations[j] >= citations[i])
                    count++;
                if(count == citations[i]){
                    max = citations[i];
                    count = 0;
                    break;
                }
                if(j == size-1 && count > max){
                    max = count;
                }
            }
             count = 0;
        }
    }
    return max;
}