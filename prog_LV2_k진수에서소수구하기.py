def solution(n, k):
    three = ""
    while True:
        if n==0:
            break
        three = three + str(n%k)
        n = n//k;
        
    three = three[::-1]
  #  print(three)
    
    li = three.split('0')
    li2 = []
    for i in li:
        if i != '':
            li2.append(i)
   # print(li2)
    li = li2
    answer = 0
    for i in li:
        if is_prime(int(i)):
            answer = answer+1
    return answer

def is_prime(n):
    if n==2 or n==3:
        return True
    elif n==1 or n%2==0 or n%3 ==0:
        return False
    else:
        for i in range(3, int(n**0.5)+1,2):
            if n%i==0:
                return False
    return True
