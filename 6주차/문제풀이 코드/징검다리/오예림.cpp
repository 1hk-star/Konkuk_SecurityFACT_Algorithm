#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int size = rocks.size();
    if(n==size) {
        return distance;
    }

    // rocks.push_back(0);
    // rocks.push_back(distance);
    sort(rocks.begin() , rocks.end());    
    int i, j;
    int dist[size+1];
    dist[0] = rocks[0];
    dist[size] = distance-rocks[size];
    int left, right;
    left=dist[0];
    right = distance; //6th
    //4차에 변경
    for(i=0 ; i<size-1 ; i++ ) {
        dist[i+1] = rocks[i+1]-rocks[i];
        if(left>dist[i+1]) {
            left = dist[i+1];
        }
        if(right < dist[i+1]) {
            right = dist[i+1];
        }
    }
    answer = right;

    while( left<=right ) {
        cout << "left : " << left << " , right : " << right << endl;
        int broke = 0;
        int mid = (left+right)/2;
        // cout << "left : " << left << " ,  right : " << right << " = mid : " <<  mid << " & " << answer ;
        long long temp=0;
        // for(i = 0 ; i<i.dist.size() ;  ){
        //     if(dist[i]<mid) {
        //         broke++;
        //         temp += dist[i]+dist[i+1];
        //         if(temp>=mid) {
        //             i++;
        //             temp=0;
        //         }else {
        //             i+=2;
        //         }
        //     }
        //     else {
        //         i++;
        //     }
        // }
        temp=0;
        broke=0;
        for(i=0 ; i<size+1 ; i++) {
            if(dist[i]+temp < mid) { // dist[i] => dist[i]+temp 6th
                temp+=dist[i];
                broke++;
            }
            else {
                temp=0;
            }

        }
        // cout  << " , temp : " << temp << " , broke = " << broke << endl;
        //<= 을 <로 수정 등호 제외

        if(broke >= n) {
            right=mid-1;
            if(answer > mid) {
                answer = mid;
            }
        }
        else {
            left = mid+1;
        }
        cout << "mid : " << mid << " , broke : " << broke << " , answer : " << answer << endl;
    }
    return answer;
}

int main() {
    vector<int> rocks;
    rocks.push_back(2);
    rocks.push_back(14);
    rocks.push_back(11);
    rocks.push_back(21);
    rocks.push_back(17);
    cout << solution(25, rocks, 5) << endl;
    // cout << lower_bound(rocks.begin(), rocks.end(), 21) -rocks.begin();
    // cout << lower_bound(rocks.begin(), rocks.end(), 25) -rocks.begin();
    rocks.clear();
    rocks.push_back(1);
    rocks.push_back(2);
    rocks.push_back(3);
    rocks.push_back(4);
    cout << solution(14 , rocks, 3) <<  endl;

} 
