prime=[0]*10005
n=int(input())
ans=0
for i in range(2,n+1):
    if(prime[i]==1):continue
    j=i*i
    while(j<=n):
        prime[j]=1
        j+=i
for i in range(2,n//2+1):
    if(prime[i]==1 or prime[n-i]==1):print(1);continue;
    ans=max(ans,i*(n-i))
print(ans)
