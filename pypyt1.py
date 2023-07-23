mul=1
ans=0
n=int(input())
for i in range(1,n+1):
    mul*=i
    ans+=mul
print(ans)
