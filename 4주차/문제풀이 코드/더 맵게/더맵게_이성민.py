import heapq
 
def solution(scoville, k):
    answer = 0;
    heap = scoville[:]
    
    heapq.heapify(heap)
    
    while heap[0]<k :
        
        if (len(heap) >1):
            a = heapq.heappop(heap)
            b = heapq.heappop(heap)
            heapq.heappush(heap, a+ b*2 )
                                  
            answer +=1
        else :
            return -1
            
    return answer
    
    
    
    