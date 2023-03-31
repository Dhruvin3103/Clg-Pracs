from prettytable import PrettyTable
#process|arrival time|burst time  
# ques1 =[[1,2,6],
#        [2,5,2],
#        [3,1,8],
#        [4,0,3],
#        [5,4,4]]
# question sample 2 
ques1 =[[1,1,7],
       [2,2,5],
       [3,3,1],
       [4,4,2],
       [5,5,8]]
ques = sorted(ques1,key=lambda x:x[1])
time = 0
process =[]
gantt = []
completed = [0 for i in ques]

def check(a):
    flag=0
    for i in a:
        if(i!=0):
            flag=flag+1
    if(flag==len(a)):
        return 1
    else: return 0
            

def min(a,time):
    temp=[]
    for i in a:
        a1=[]
        if(completed[i[0]-1]==0 and i[1]<=time):
            a1.append(i[2])
            a1.append(i[0])
            temp.append(a1)
    return sorted(temp)[0]  

i=0
while check(completed)==0:
    if(ques[i][1]==0):
        gantt.append(0)

    if(ques[i][1]!=0 and time==0):
        gantt.append(0)
        gantt.append(ques[i][1])
        process.append(-1)
        time=ques[i][1]
    elif(time>=ques[i][1]):
        gt = min(ques,time)
        gantt.append(time +gt[0])
        time = time +gt[0]
        process.append(gt[1])
        completed[gt[1]-1]=gantt[-1]
        i=i+1
               
taT = [x-y[1] for x,y in zip(completed,ques)]
waT = [x-y[2] for x,y in zip(taT,ques)]

t = PrettyTable(['Processes', 'Arrival Time ', 'Burst Time', 'completion Time','Turn around Time', 'Waiting Time'])
for i in range(len(ques)):
    t.add_row([ques[i][0], ques[i][1],ques[i][2],completed[i],taT[i],waT[i]])
print("Gantt Chart :")
proc = "   "
t1 = ""
for i in process:
    proc = proc+"  "+str(i)
for i in gantt:
    t1 = t1 + "   "+str(i)
print(proc)
print(t1)
print(t)
print("average waiting Time : "+str(round(sum(waT)/len(waT),3)))
print("average turn around  Time : "+str(round(sum(taT)/len(taT),3)))
    
    
# chatgpt ka sol 
# def min(a,time):
#     temp=[]
#     for i in range(len(a)):
#         a1=[]
#         if(completed[i]==0):
#             a1.append(a[i][2])
#             a1.append(i+1)
#             temp.append(a1)
#     if len(temp[:time]) > 0:
#         print(temp[:time])
#         print(sorted(temp[:time])[0],'here' )
#         return sorted(temp[:time])[0]
#     else:
#         return [0,0]
