"""
blue 2:01.12
red 2:13.44
red 1:56.33
blue 2:03.31
red 2:04.84
red 2:06.67
blue 1:58.14
blue 2:07.31
"""
def itemmode() :
    arr =[]
    speed = []
    times = []
   

    for i in range(0,8):
        st = input('')
        arr.append(st)
        tmp = str(arr[i]).split(' ')
        speed.append(tmp)
        times.append(speed[i][1])
    print(speed[times.index(min(times))][0])
def speed():
    point = [10,8,6,5,4,3,2,1,0]
    arr =[]
    speed = []
    times = []
    red = 0
    blue = 0
    for i in range(0,8):
        st = input('')
        arr.append(st)
        tmp = str(arr[i]).split(' ')
        speed.append(tmp)
        times.append(speed[i][1])
    print(times)
    y = sorted(times)
    print(y)
    print(arr)
 
           
    print('======================================================')
    for j in range(0,8):
       
        if(arr[times.index(y[j])].split(' ')[0] == 'red'):
            y[0]=y[0].replace('.','')
            y[0]=y[0].replace(':','')
            y[j]=y[j].replace('.','')
            y[j]=y[j].replace(':','')
            # print(y[j],y[0])
            #....................................
            red = red + point[j]
            print(int(y[j],base=12)-int(y[0],base=12))
            if(int(y[j],base=12)-int(y[0],base=12)>=100):
                red = red - point[j]
            print('red:',red)
    print(blue, red)
                
                
#itemmode()
speed()