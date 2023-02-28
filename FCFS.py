cpu = [4,2,5,1,3]
arr = [0,3,4,2,1]
p = []
gantt = []
bu = []
# x = int(input("Enter the number of process : "))
# for i in range(x):
    
#     cpu.append(int(input("cpu time for "+str(i)+" ")))
#     arr.append(int(input("arrival time for "+str(i)+" ")))
    
ans = sorted(list(zip(arr,cpu)))



for i in range(5):
    if i==0:
        gantt.append(ans[i][1]+0)
    else:
        gantt.append(ans[i][1]+gantt[i-1])

for a,b in ans:
    p.append("p"+str(a+1))
    bu.append(b)
print("Process :")
print(p)
print("Completion time :")
print(gantt)
print("Burst time :")
print(bu)

taT = [x-y for x,y in zip(gantt,sorted(arr))]
waT = [x-y for x,y in zip(taT,bu)]
print("Turn Around time : ")
print(taT)
print("waiting time : ")
print(waT)

