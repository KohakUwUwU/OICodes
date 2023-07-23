tmp=""
arr=['','']
cnt=1
s=input()
S=''
bn=[]
bnt=0
for i in range(0,len(s)):
    if(s[i]!=' '):
        if(s[i]>='A' and s[i]<='Z'):
            if(s[i]=='A'):S+='a'
            if(s[i]=='B'):S+='b'
            if(s[i]=='C'):S+='c'
            if(s[i]=='D'):S+='d'
            if(s[i]=='E'):S+='e'
            if(s[i]=='F'):S+='f'
            if(s[i]=='G'):S+='g'
            if(s[i]=='H'):S+='h'
            if(s[i]=='I'):S+='i'
            if(s[i]=='J'):S+='j'
            if(s[i]=='K'):S+='k'
            if(s[i]=='L'):S+='l'
            if(s[i]=='M'):S+='m'
            if(s[i]=='N'):S+='n'
            if(s[i]=='O'):S+='o'
            if(s[i]=='P'):S+='p'
            if(s[i]=='Q'):S+='q'
            if(s[i]=='R'):S+='r'
            if(s[i]=='S'):S+='s'
            if(s[i]=='T'):S+='t'
            if(s[i]=='U'):S+='u'
            if(s[i]=='V'):S+='v'
            if(s[i]=='W'):S+='w'
            if(s[i]=='X'):S+='x'
            if(s[i]=='Y'):S+='y'
            if(s[i]=='Z'):S+='z'
        else:
            S+=s[i]
    else:
        S+=' '
for i in range(0,len(S)):
    if(S[i]!=' '):
        arr[cnt]+=S[i]
    else:
        cnt+=1
        arr.append('')
arr.sort()
for i in range(1,cnt+1):
    print(arr[i],end=' ')
last=arr[0]
bn.append(0)
for i in range(1,cnt+1):
    if(last==arr[i]):
        bn[bnt]+=1
    else:
        bn.append(1)
        bnt+=1
        last=arr[i]
for i in range(0,bnt):print(bn[i])
