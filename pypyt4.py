s=input()
ss=[]
for i in range(0,4):
    ss.append(int(s[i]))
    ss[i]+=5;
    ss[i]%=10
print(ss[3],end='')
print(ss[2],end='')
print(ss[0],end='')
print(ss[1],end='')
