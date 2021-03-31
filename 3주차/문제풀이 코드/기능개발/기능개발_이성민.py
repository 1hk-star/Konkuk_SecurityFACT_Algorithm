def solution(progresses, speeds):
    answer = []          
    finishedPrgrs = 0
    
    previousMax = 0
    
    initial_delta = 100 - progresses[0]
    quotient, remainder = divmod(initial_delta,speeds[0])
    if(remainder == 0):
        previousMax = quotient
    else:
        previousMax = quotient + 1
    
    for i in range(len(progresses)):
        delta = 100 - progresses[i]
        
        quotient, remainder = divmod(delta,speeds[i])
        
        if(remainder == 0):
            day = quotient
        else:
            day = quotient + 1
        
        if(day <= previousMax ) :
            finishedPrgrs +=1
        else:
            answer.append(finishedPrgrs)
            finishedPrgrs = 1
            previousMax = day
    
    answer.append(finishedPrgrs)
    return answer
    
    
    