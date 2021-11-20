""" 처음 생각한 틀린 코드 시간초과 및 일부 테케 비통과
처음 생각한 개념 가짓 수 만큼의 집합 길이로 시작해서 집합을 차례대로 앞에서부터 탐색한 후 그 집합이 포함한 가짓 수가 모자라면 집합 길이를 늘려서 완전탐색
def solution(gems):
    answer = []
    kind = set(gems);
    n = len(kind)
    m = len(gems)
    length = n;
    while True:
        for i in range(m-length):
            if len(set(gems[i:i+length]))==n:
                print(gems[i:i+length])
                return [i+1,i+length]
        length+=1
        if length>m:
            return [1,m]
        
    return answer
"""
#타인코드 max heap
def solution(gems):
    gemSet = set()
    for gem in gems:
        if gem not in gemSet:
            gemSet.add(gem)
    kinds = len(gemSet)
    
    answer = [1, len(gems)]
    left = 0; right = 0
    while left <= right and right < len(gems):
        gemSet = set()
        for gem in gems[left:right+1]:
            if gem not in gemSet:
                gemSet.add(gem)
        
        if len(gemSet) == kinds:
            if answer[1]-answer[0] > right-left:
                answer = [left+1, right+1]
            left += 1

        elif len(gemSet) < kinds:
            right += 1
        
    return answer
