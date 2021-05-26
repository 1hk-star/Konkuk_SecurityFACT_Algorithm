#1. 명령어를 받아서
#2. 규칙대로 처리하고  
#3. 비어 있으면 [0,0] 아니면 [최댓값,최솟값]

#<규칙>
#I 5 = 5 삽입
#D 1 = 최댓값 삭제
#D-1 = 최솟값 삭제

#operations는 길이가 1 이상 1,000,000 이하인 문자열 배열입니다.

import heapq
def solution(operations):
    answer = []
    heap = []
    
    for i in range(len(operations)) :
        if operations[i].split(" ")[0] == "D" and len(heap)>0:
            
            if operations[i].split(" ")[1] == "1" :
                heap.pop(heap.index(heapq.nlargest(1, heap)[0]))
            
            else:
                heapq.heappop(heap)
        if operations[i].split(" ")[0] == "I" :
            heapq.heappush(heap,int(operations[i].split(" ")[1]))
        
        
    if len(heap) ==0:
        return [0,0]
    else :
        answer.append(heapq.nlargest(1,heap)[0])
        answer.append(heapq.nsmallest(1,heap)[0])
        return answer
