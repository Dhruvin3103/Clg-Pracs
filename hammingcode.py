def checkparity(a,n,p,m):
    l=[]
    
    for i in range(2**(n-1)-1,len(a),2**n):
        l = l+ a[i:i+2**(n-1)]
    if m==1:
        if(l.count(1)%2==0):
            a[2**(n-1)-1]=p
        else:
            a[2**(n-1)-1]= 1-p
    elif m==0:
        # print(l,n)
        if(len(l)==0):
            return ""
        if(l.count('1')%2==0):
            # print(p,'e')
            return str(p)
        else:
            # print(p,'o')
            return str(1-p)
    # print(a)
# d = 1011
def transmit(d,par,m):
    ds = str(d)[::-1]
    if m==1:
        p=0
        for i in range(len(ds)):
            if(2**i>=len(ds)+i+1):
                p=i
                break;
        dataL = []
        j=0
        k=0 
        for i in range(len(ds)+p):
            if(i==2**j):
                dataL.insert(i-1,9)
                j=j+1 
            else:
                dataL.insert(i,int(ds[k]))
                k=k+1            
        for i in range(0,p):
            checkparity(dataL,i+1,par,m)

        dataLR=dataL[::-1]  
        trans = ''.join(str(i) for i in dataLR)
        print("Transmitted Message : "+trans)
    elif m==0:
        print("recevied code : "+ds[::-1])
        r=""
        for i in range(0,len(ds)):
            r = r + checkparity(list(ds),i+1,par,m)
        # print(int(r[::-1]),int(str(r),2))
        if int(str(r),2)==0:
            print("no errors")
        else:
            pos = int(r[::-1],2)
            ds = ds[::-1]
            # print(pos,len(ds)-pos,r,ds)
            if ds[len(ds)-pos] == '1': 
                ds= ds[:len(ds)-pos]+'0'+ds[len(ds)-pos+1:]
            elif ds[len(ds)-pos] == '0':
                ds= ds[:len(ds)-pos]+'1'+ds[len(ds)-pos+1:]
            
            print("there are errors correct code : "+ds)      
par = 9
while (par!=1 and par!=0):
    par = int(input("Enter the parity (1 for odd and 0 for even ): "))
    if(par!=1 and par!=0):
        print("Enter correct parity")
transmit(int(input("Enter the data bit : ")),par,int(input("Enter the mediun 1 for transmission and 0 for receive : ")))
# transmit(1011110,1,0)
# transmit(1010001,0,0)
