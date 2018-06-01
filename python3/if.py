#-*-coding:utf-8-*-
clear = "\n*70"
money = 2000
nogada = 0
mode = 0
b = 0
a = 1
ch = True
print(money)
while(True):
    mode = input('노가다:1 || 돈쓰기:2')
    if(mode == '1'):
        while(True):
            if(nogada >= 10):
                ch = True
            a = input("a를누르면 노가당\n")
            if(a == 'a'):
                money+=100
                print(money)
                nogada+=1
            elif(a == '/'):
                money+=100000
                print(money)
            else:
                break
    elif(mode == '2' and ch == True):
        print("뭐할래?")
        print("보유 금액:{0}".format(money))
        b = input("""차사기:1 집사기:2 옷사기:3 4:구재금융\n""")
        if(b == '1' and money>5000):
            money-=5000
            print("잔액:{0}".format(money))
        elif(b == '2' and money>20000):
            money-=20000
            print("잔액:{0}".format(money))
        elif(b == '3' and money>50):
            money-=100
            print("잔액:{0}".format(money))
        elif(b == '4' and money == 0):
            print("구재금융")
            print("하지만 너는 10번동안 물건을 못삼")
            money+=5000
            print(money)
            ch = False
        elif(b=='5'):
            money = 0

        else:
            print("ERROR")
            pass
        
    
