import math

def solution(fees, records):
    answer = []
    dic = {}
    carlist = set()
    for i in records:
        num = i.split()[1]
        time = i.split()[0]
        log = i.split()[2]
        carlist.add(num)
        time = int(time.split(':')[0])*60 + int(time.split(':')[1])
        if num not in dic:
            dic[num] = [time]
        else:
            dic[num].append(time)
    dicts = sorted(dic.items(), key = lambda item: item[0])
    carlist = list(carlist)
    carlist.sort()
    answerdic = {}
    for i in dic:
        #print(i)
        parktime = 0
        priceofcar = 0
        for idx, j in enumerate(dic[i]):
            price = 0
            if idx%2==1:
                continue
            if idx%2==0 and len(dic[i])>=idx+2:
                parktime = parktime+ dic[i][idx+1] - dic[i][idx]
            if idx == len(dic[i])-1 and len(dic[i])%2==1:
                parktime = parktime+ 23*60+59 - dic[i][idx]
            #print(idx, parktime, len(dic[i]))
        if parktime<=fees[0]:
            price = fees[1]
            priceofcar = priceofcar+price
        else:
            price = fees[1] + math.ceil((parktime-fees[0])/fees[2])*fees[3]
            priceofcar = priceofcar+price
        #print(priceofcar)
        answerdic[i] = priceofcar
    answer = []
    #print(answerdic)
    for i in carlist:
        answer.append(answerdic[i])
    return answer
    
