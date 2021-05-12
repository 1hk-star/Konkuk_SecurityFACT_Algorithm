#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {

    long long answer = 0;
    // vector<int> temp;
    // int m = times.size();
    // int i, j;
    // if(n<m) {
    //     sort(times.begin(), times.end());
    //     for(i=0 ; i<n ; i++ ){
    //         answer+=times[i];
    //     }
    // }
    // else if( n == m) {
    //     for(int time : times) {
    //         answer+=time;
    //     }
    // }
    // else {
    //     for (int time : times) {
    //         temp.push_back(time);
    //     }
    //     n-=m;
    //     while(n>0) {
    //         int mean = *min_element(temp.begin(), temp.end());
    //         for (i=0 ; i<temp.size() ; i++ ){
    //             temp[i]-=mean;
    //         }
    //             int index = find(temp.begin() , temp.end(), 0) - temp.begin();
    //             temp[index] = times[index];
    //             n--;
    //             answer+=mean;
    //     }       

    //     for(i=0 ; i<temp.size() ; i++ ) {
    //         temp[i]+=times[i];
    //     }
    //     answer += *min_element(temp.begin() , temp.end());


    // }
    // 1차 시도 결과 9번을 제외한 모든 테스트에서 실패 => 생각해보니 심사 받는 사람의 수와 심사관의 수의 비교가 필요가 없다 예를 들어 2, [1, 10, 30, 40] 인 경우는 1에다가 시험을 하는 게 좋다
    // for (int time : times) {
    //         temp.push_back(time);
    //     }
    //     n-=m;
    //     while(n>0) {
    //         int mean = *min_element(temp.begin(), temp.end());
    //         for (i=0 ; i<temp.size() ; i++ ){
    //             temp[i]-=mean;
    //         }
    //             int index = find(temp.begin() , temp.end(), 0) - temp.begin();
    //             temp[index] = times[index];
    //             n--;
    //             answer+=mean;
    //     }       

    //     for(i=0 ; i<temp.size() ; i++ ) {
    //         temp[i]+=times[i];
    //     }
    //     answer += *min_element(temp.begin() , temp.end());

    // vector<int> temp;
    // for(int time : times) {
    //     temp.push_back(time);
    // }
    // int index=0; // 이전 사람이 선택한 심사관 index값
    // int mean; //이번 사람이 선택할 심사관의 시간
    // while(n>=0) {
    //     mean = *min_element(temp.begin(), temp.end());
    //     index = find(temp.begin() , temp.end(), index);

    // }
    // return answer;

    //이진 탐색 사용
    // int left = 1;
    // int max = *max_element(times.begin() , times.end());
    // int right = n*max;
    // int mid = (left+right)/2;
    // answer = 9999999999;

    // while (left < right) {
    //     mid = (left+right)/2;
    //     int total = 0;
    //     for(int t : times) {
    //         total+=mid/t;
    //     }
    //     if (total>=n) {
    //         right = mid-1;
    //         if(answer>=mid) {
    //             answer = mid;
    //         }
    //     }
    //     else {
    //         left = mid+1;
    //     }
    // }

    long long min = *min_element(times.begin() , times.end());
    long long left = min;
    long long right = min*n;
    answer = right;
    long long checked = 0;

    while(left<=right) {
        long long mid = (left+right)/2;
        checked = 0;
        for(int time : times) {
            checked+=mid/time;
            if(checked>=n) {
                right = mid-1;
                if(answer > mid) {
                    answer=mid;
                }
                break;
            }
        }
        if(checked<n) {
            left = mid+1;
        }
    }

    return answer;
} 
