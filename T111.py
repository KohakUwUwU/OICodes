n=input()
len=len(n)
n=int(n)
print("This is a",end=" ")
if(len==1):print("one",end=' ')
if(len==2):print("two",end=' ')
if(len==3):print("three",end=' ')
if(len==4):print("four",end=' ')
if(len==5):print("five",end=' ')
print("digit number")
while n>0:
    print(n%10,end='')
    n//=10
