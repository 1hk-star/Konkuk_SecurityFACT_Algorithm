#include <string>
#include <vector>
 
using namespace std;
 
vector<int> solution(vector<int> prices) {
    int size = prices.size();
    vector<int> answer(size);
  
    int j;
    
    for(int i = 0;i<size-1;i++){
        int current = prices[i];
        for(j=i+1;j<size;j++){
            if(current <= prices[j]){
                answer[i]++;
            } 
            else{
                answer[i]++;
                break;
            }
                
        }
        
    }
    
    answer[size - 1] = 0; //default
    return answer;
}