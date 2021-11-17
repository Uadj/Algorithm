import heapq;

def solution(jobs):
    length = len(jobs)
    now = 0;
    before = -1;
    num = 0;
    arr = []
    check = 0
    while check < length:
        for j in jobs:
            if before < j[0] <= now:
                heapq.heappush(arr, [j[1],j[0]])
        if arr:
            temp = heapq.heappop(arr)
            before = now;
            now += temp[0]
            num += now-temp[1]
            check +=-1
        else:
            now +=-1
    return int(num/length)
