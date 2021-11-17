#https://programmers.co.kr/learn/courses/30/lessons/43163
#BFS
#depth 변환한 횟수
import collections
def solution(begin, target, words):
    answer = 0
    if target not in words:
        return 0
    else:
        visited=[]
        queue = collections.deque()
        queue.append([begin,0])
        return bfs(queue, visited, words, target)
    

def bfs(queue, visited, words, target):
    if not queue:
        return 0
    now, depth = queue.popleft()
    for j in words:
        cnt = 0
        if j not in visited:
            for i in range(len(now)):
                if now != j:
                    if j[i] != now[i]:
                        cnt += 1
                    #words 내의 단어로 한 번에 한 개의 알파벳만 바꿀 수 있음.
                    if cnt >= 2 :
                        continue
            #한 개만 다른 단어를 발견했을 때
            if cnt == 1:
                visited.append(j)
                queue.append([j,depth+1])
                if j == target:
                    return depth+1
        else:
            continue
        
    return bfs(queue,visited,words,target)
