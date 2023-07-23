s=input()
year=0;
month=0;
day=0;
b=0
ans=0
run=[0,31,29,31,30,31,30,31,31,30,31,30,31]
ping=[0,31,28,31,30,31,30,31,31,30,31,30,31]
for i in range (0,4):
    year=year*10+int(s[i])
for i in range (5,7):
    month=month*10+int(s[i])
for i in range (8,10):
    day=day*10+int(s[i])
print(year,month,day)
if(year%100!=0 and year%4==0 or year%400==0):b=1;
if(b==1):
    for i in range(1,month):
        ans+=run[i]
    ans+=day
else:
    for i in range(1,month):ans+=ping[i]
    ans+=day
print(ans)
    
