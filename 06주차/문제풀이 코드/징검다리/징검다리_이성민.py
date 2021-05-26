# distance = 출발지점과 끝점이 떨어진 거리 : 0이 출발점 25이 끝 점
# rocks = 바위의 좌표가 주어짐
# n = 돌을 몇 개 뺄 것인지
#
#distance 	rocks 	                n 	    return
#25 	    [2, 14, 11, 21, 17] 	2 	    4
#return이 될 수 있는 값 중 중간 값 지정     int((1+distance)/2)
#0번 돌부터 마지막 돌까지 돌면서 사이 간격이 x보다 크면 pass 
#작으면 그 돌을 없애고 n을 하나 줄임
#만약 전부 돌았는데 n이 남으면      x를 늘림
#만약 전부 돌았는데 n이 부족하면     x를 줄임


def solution(distance, rocks, n):
    
    answer = 0
    rocks.sort()
    
    low = 0
    high = distance
    
    prevRock = 0
    
    while(low<high):
        
        rmRock = 0
        prevRock = 0
        mid = int((low+high)/2)   #내림
        
        for i in range(len(rocks)):
            if(rocks[1] - prevRock) < mid :
                rmRock +=1
            else:
                prevRock = rocks[1]
            if(i == len(rocks)-1):
                if(distance - prevRock < mid):
                    rmRock +=1
        if(rmRock <= n):
            if(answer < mid):
                answer = mid
            low = mid+1
        else:
            high = mid-1
    return answer

