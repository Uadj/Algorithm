#BFS
from collections import deque

def solution(land):
    
    answer = 0
    
    dx=[0,0,1,-1]
    dy=[1,-1,0,0]
    
    m = len(land[0])
    n = len(land)
    visited = [[0 for i in range(m)] for j in range(n)]
    colCount = [0 for i in range(m+1)]
    #print (visited);
    
    def bfs(x,y):
        count = 0
        q = deque()
        q.append((x,y))
        minCol, maxCol = y,y
        while q:
            x,y = q.popleft()
            minCol = min(y,minCol)
            maxCol = max(y,maxCol)
            visited[x][y]=1
            count+=1
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < n and 0 <= ny < m:
                    #print(nx, ny)
                    if visited[nx][ny]==0 and land[nx][ny]==1:
                        visited[nx][ny] = 1
                        q.append((nx,ny))
                        #print(ny,nx)
        print(count)
        for i in range(minCol, maxCol+1):
            colCount[i] += count
    for i in range(n):
        for j in range(m):
            if visited[i][j]==0 and land[i][j]==1:
                bfs(i,j)
    print(colCount)
    answer=max(colCount)
    return answer
              
   
