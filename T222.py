n=int(input())
if(n<6):print("None")
else:
    for i in range (6,n):
        if(i==6):
            print("6=1+2+3")
            continue
        Gsz,Esz,cnt=0,0,0
        G=[0];
        E=[0]
        for j in range (1,int(i**0.5)):
            if(i%j!=0):continue;
            G.append(j);Gsz+=1;cnt+=j;
            if(j!=1 and j*j!=i):
                E.append(i//j);
                Esz+=1;
                cnt+=i//j;
        if(cnt!=i):continue;
        print(i,end='=')
        for j in range (1,Gsz+1):
            print(G[j],end='+')
        j=Esz
        while j>1:
            print(E[j],end='+')
            j-=1
        print(E[1])
