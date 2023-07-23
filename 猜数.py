import random
randNum=22
print('Welcome to our number guessing game.')
chanceNum=int(input('Enter the number of chances you want to have:\n'))
numList=[]
b=0
print('Please enter a number between 1-100:')
for i in range(1,chanceNum):
    inp=int(input())
    if inp<1 or inp >100:
        print('Please enter a number between 1-100:')
        i-=1
        continue
    elif inp>randNum:
        print('Greater, guess again.')
        numList.append(inp)
    elif inp<randNum:
        print('Less, guess again.')
        numList.append(inp)
    else:
        b=1
        numList.append(inp)
        print('You win, congratulation! Your guesses are',end=' ')
        for j in (0,len(numList)-1):
            print(numList[j],end=' ')
        print(numList[len(numList)-1],end='.')
        print(' The number is ',end='')
        print(randNum)
        break
if b==0:
    inp=int(input())
    if inp == randNum:
        print('You win, congratulation! Your guesses are',end=' ')
    else:
        print('Sorry,you run out of chances. Your guesses are',end=' ')
    for j in (0,len(numList)-1):
        print(numList[j],end=' ')
    print(numList[len(numList)-1],end='.')
    print(' The number is ',end='')
    print(randNum)
