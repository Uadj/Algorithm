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
import heapq

def solution(n, works):
    if n >= sum(works):
        return 0
    
    works = [-w for w in works]
    heapq.heapify(works)
    for _ in range(n):
        i = heapq.heappop(works)
        i += 1
        heapq.heappush(works, i)
    
    return sum([w ** 2 for w in works])
