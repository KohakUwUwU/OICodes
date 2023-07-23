import random



t_num=0
chances=0
inp=0
answer_list=[]


def Init():
    global t_num
    t_num=random.randint(1, 100)
    print('Welcome to the number guessing game!')


def ChancesInput():
    global chances
    chances=int(input('Please enter the number of chances you want.'))


def GuessingOutput():
    print('Please enter a number between 1-100:')


def GuessingInput():
    global inp
    inp=int(input('Please enter a number between 1-100:'))


def Greater():
    print("It's greater, please try again")


def Smaller():
    print("It's smaller, please try again")


def Win():
    global answer_list
    global t_num
    print('Congratulation, you win! Your guesses are: '+' '.join(answer_list)+'. The target number is: '+str(t_num))


def Lose():
    global answer_list
    global t_num
    print('Sorry, you run out of chances. Your guesses are: '+' '.join(answer_list)+'. The target number is: '+str(t_num))


def Play():
    global t_num
    global chances
    global inp
    global answer_list
    while True:
        t_num=0
        chances=0
        answer_list=[]
        while True:
            try:
                ChancesInput()
                break
            except: continue
        while chances>0:
            chances-=1
            while True:
                try:
                    GuessingInput();
                    break
                except: continue
            answer_list.append(str(inp))  
            if inp<0 or inp>100: GuessingOutput();
            elif inp>t_num: Greater()
            elif inp<t_num: Smaller()
            elif inp==t_num: Win(); break
        if chances==0: Lose()
        option=''
        while True:
            option=input('The game is over. Do you want to play again or exit? Please enter "play again" or "exit".')
            if option=='play again': break
            elif option=='exit': break
        if option=='exit': break





Play()
