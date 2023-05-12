from prettytable import PrettyTable
cpu = [4,2,5,1,3]
arr = [0,3,4,2,1]
p = []
gantt = []
bu = []
ans = sorted(list(zip(arr,cpu)))
for i in range(5):
    if i==0:
        gantt.append(ans[i][1]+0)
    else:
        gantt.append(ans[i][1]+gantt[i-1])
for a,b in ans:
    p.append("p"+str(a+1))
    bu.append(b)
taT = [x-y for x,y in zip(gantt,sorted(arr))]
waT = [x-y for x,y in zip(taT,bu)]
t = PrettyTable(['Processes', 'Arrival Time ', 'Burst Time', 'completion Time','Turn around Time', 'Waiting Time'])

for i in range(len(p)):
    t.add_row([p[i], sorted(arr)[i],bu[i],gantt[i],taT[i],waT[i]])

print("Gantt Chart :")
proc = ""
t1 = "0"
for i in p:
    proc = proc+"  "+str(i)
for i in gantt:
    t1 = t1 + "   "+str(i)
print(proc)
print(t1)
print(t)
print("average waiting Time : "+str(round(sum(waT)/len(waT),3)))
print("average turn around  Time : "+str(round(sum(taT)/len(taT),3)))
    
    
