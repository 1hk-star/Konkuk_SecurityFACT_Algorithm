def solution(bridge_length,weight,truck_weights):
    answer = 0
    onBridge = [0]*bridge_length 
    
    totalSum = 0
    #front and rear for onBridge array
    frontB = -1
    rearB = bridge_length - 1
  
    while truck_weights:
        answer+=1
        
        totalSum -=onBridge[frontB]
        onBridge[frontB] = 0
        
        if(totalSum + truck_weights[0]<=weight):
                onBridge[rearB]=truck_weights[0]
                totalSum += truck_weights[0]
                truck_weights.pop(0)
                
                
        
        frontB +=1
        rearB +=1    
        if frontB==bridge_length : 
            frontB = 0
        if rearB== bridge_length :
            rearB = 0
        
    answer +=bridge_length 
    return answer

