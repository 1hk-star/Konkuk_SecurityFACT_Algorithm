def solution(array, commands):
    answer = []
    
    for i in range(len(commands)):
        list_ = commands[i]
        start = list_[0]
        end = list_[1]
        count = list_[2]
        
        array_ = array[start-1:end]
        array_.sort()
        answer_ = array_[count-1]
        
        answer.append(answer_)
    
    return answer
