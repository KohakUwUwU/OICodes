s=0
seg=""
n=input()
len=len(n)
if(len==1):seg="one"
if(len==2):seg="two"
if(len==3):seg="three"
if(len==4):seg="four"
if(len==5):seg="five"
print("This is a",seg,"digit number")
n=int(n)
while(n>0):
    print(n%10,end='')
    n//=10
    
