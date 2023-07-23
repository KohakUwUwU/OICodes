import random
randNum=random.randint(1, 100)
print('Welcome to our number guessing game.')
chanceNum=int(input('Enter the number of chances you want to have:\n'))
numList=[]
b=0
print('Please enter a number between 1-100:')
i=1
while i<chanceNum:
    inp=int(input())
    if inp>100 or inp<0:
        print('Please enter a number between 1-100:')
        continue
    numList.append(inp)
    if inp<randNum:
        print('Less, guess again.')
    elif inp>randNum:
        print('Greater, guess again.')
    else:
        b=1
        print('You win, congratulation! Your guesses are',end='')
        for j in numList:
            print(' ',end=str(j))
        print('. The number is ',end='')
        print(randNum,end='.')
        break
    i+=1
if b==0:
    inp=int(input())
    numList.append(inp)
    if inp==randNum:
        print('You win, congratulation! Your guesses are',end='')
    else:
        print('Sorry, you run out of chances. Your guesses are',end='')
    for j in numList:
        print(' ',end=str(j))
    print('. The number is ',end='')
    print(randNum,end='.')
