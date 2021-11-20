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
#타인코드 
def solution(gems):
    gemSet = set()
    for gem in gems:
        if gem not in gemSet:
            gemSet.add(gem)
    kinds = len(gemSet)
    
    gemDict = {gems[0]: 1}
    answer = [1, len(gems)]
    left = 0; right = 0
    while left <= right and right < len(gems):
        if len(gemDict) == kinds:
            if answer[1]-answer[0] > right-left:
                answer = [left+1, right+1]
            
            gemDict[gems[left]] -= 1
            if gemDict[gems[left]] == 0:
                del gemDict[gems[left]]
            left += 1

        elif len(gemDict) < kinds:
            right += 1
            if right >= len(gems):
                break
                
            if gems[right] not in gemDict:
                gemDict[gems[right]] = 1
            else:
                gemDict[gems[right]] += 1
        
    return answer
