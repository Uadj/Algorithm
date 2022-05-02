def solution(id_list, report, k):
    reported = {}
    reporter = {}
    for i in id_list:
        reported[i] = set()
        reporter[i] = set()
    for j in report:
        st = j.split()
        #print(st)
        reporterman = st[0]
        reportedman = st[1]
        reported[reportedman].add(reporterman)
        reporter[reporterman].add(reportedman)
    answer = []
    reportedlist = []
    for key, value in reported.items() :
        #print(len(value))
        if len(value) >= k:
            reportedlist.append(key)
    for i in id_list:
        cnt = 0
        for j in reportedlist:
            if j in reporter[i]:
                cnt = cnt+1
        answer.append(cnt)
    #print(reported)
    #print(reporter)
    
    return answer
