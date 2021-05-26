#priorities = 중요도 배열
#location = 선호 문서
#return = 선호 문서가 몇 번째에 인쇄되는지 출력

#<logic>
#queue에 prioirties 배열 저장,
#1. prioirties 배열에 인덱스를 붙이고 sort() 시키기, 


def solution(priorities, location):
    answer = 0
    sorting = priorities[:]
    sorting.sort(reverse = True)
    # 포인터는  prioirties 배열의 0 부터 마지막 요소까지 돌며 접근하기 위한 변수
    pointer = 0
    # sorting 배열에 접근하기 위한 변수
    arrPointer = 0
    
    while priorities:
    
        if (sorting[arrPointer] == priorities[pointer]):
            arrPointer +=1
            answer +=1
            if pointer == location:
                return answer
        
        
        pointer +=1
        if pointer == len(priorities):
            pointer  = 0