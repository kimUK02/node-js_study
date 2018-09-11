num = int(input('ëª‡ë²ˆ:'))
a = []
b = []
for i in range(0,num):
    st = input('--------------------------------------------')
    a.append(st)

for i in range(0,num):
    word = str(a[i]).split(' ')
    
    for j in range(0,len(word)):
        print(str(word[j])[0],end='')
    print('\n',end='')
