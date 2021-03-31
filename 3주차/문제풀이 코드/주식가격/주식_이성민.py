# [1,2,3,2,3] 이 주어질 때
# 1은 떨어지지 않음 -> 4
# 2는 떨어지지 않음 -> 3
# 3은 1초뒤 떨어짐 -> 1
# 2는 떨어지지 않음 -> 1
#3은 떨어지지 않음 -> 0
#따라서 return = [4,3,1,1,0]
#price의 요소 1~10000
#price의 요소 2~100000 -> 이중 for 문은 시간 초과

def solution(prices):
    answer = []
    currentMin = 0
    currentNum = 0
    
    #최솟값을 알아보기 위한 배열
    arrForMin = prices[:]
    #최솟값을 저장하기 위한 배열
    minvalue = []
    stack = 0
    
    currentMin = prices[-1]
    while arrForMin:
        currentNum = arrForMin.pop(-1)
        if(currentMin>=currentNum):
            currentMin = currentNum
            minvalue.append(currentMin)
        else : 
            minvalue.append(currentMin)
    
    minvalue.reverse()
 
    for i in range(len(prices)):
        if prices[i] <= minvalue[i]:
            answer.append(len(prices) - 1 - i)
        else :
            for j in (range(len(prices)-i)):
                if prices[i] > prices[i+j]:
                    answer.append(j)
                    break
    
    return answer
    
    