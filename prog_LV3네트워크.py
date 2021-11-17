# https://programmers.co.kr/learn/courses/30/lessons/43162
# BFS 딕셔너리 타입에 각 간선의 연결정보를 저장한다.
# 각 노드를 차례로 방문하여 연결된 끝까지 방문하고 체크한다. for문의 자기 차례까지 방문하지 않았다면 답에 +1한다.
import collections
def solution(n, computers):
    answer = 0
    # 딕셔너리 타입에 각 간선의 연결정보를 저장한다.
    dic = {}
    for i in range(1, len(computers)+1):
        dic[i]=[i]
        for j in range(1, len(computers[i-1])+1):
            if i!=j and computers[i-1][j-1] == 1:
                dic[i].append(j)          
    visited = []
 # 각 노드를 차례로 방문하여 연결된 끝까지 방문하고 체크한다. for문의 자기 차례까지 아직 방문하지 않았다면 답에 +1한다.
    for i in range(1,n+1):
        if [i,i] not in visited:
            visited.append([i,i])
            answer += 1
            queue = collections.deque()
            queue.append(i)
            while queue:
                now = queue.popleft()
                #print(now)
                for temp in dic[now]:
                    if [now, temp] not in visited:
                        queue.append(temp)
                        visited.append([now, temp])
    return answer
