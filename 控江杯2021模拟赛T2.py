b=0
n=(int)(input())
for i in range(1,n):
    if(i==1):continue;
    cnt=0
    Gsize=0
    Esize=0
    G=[]
    E=[]
    for j in range(1,int(i**0.5)+1):
        if i%j==0:
            cnt+=j;
            if(j!=1):cnt+=i//j
            G.append(j);Gsize+=1;
            if(j==1):continue;
            if(j*j!=i):
                E.append(i//j)
                Esize+=1;
    if(cnt!=i):
        continue;
    b=1
    print(i,end='')
    print('=',end='')
    for j in range(0,Gsize):
        print(G[j],end='')
        print('+',end='')
    j=Esize-1
    while j>0:
        print(E[j],end='')
        print('+',end='')
        j-=1
    if(Esize):print(E[0])
if(b==0):print("None")
