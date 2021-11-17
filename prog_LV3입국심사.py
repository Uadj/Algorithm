# 이분탐색
# 시작 left = 1 right = 최악의 경우(가장 긴 시간*사람 수) middle 그 중간
# 만약 middle분 걸렸을 경우 (middle//각 심사원시간)의 합은 n이 되어야한다.
import math
def solution(n, times):
    answer = 0
    left = 1
    
    right = max(times)*n
    while left<=right:
        count = 0
        middle = (left+right)//2
        for i in times:
            count+=middle//i
        if n<=count:
            answer=middle
            right=middle-1
        else:
            left=middle+1

    return answer
