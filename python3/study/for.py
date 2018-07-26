fam = ['mather', 'father','sis','bro']
for x in fam:
    print("%s %s" %(x,len(x)))
sum = 0
for i in range(1,11):
    sum += i
print(sum)

test_list = ['one','two','three']
for i in test_list:
    print(i)

a=[(1,2),(3,4),(5,6)]
for (first,last) in a:
    print(first+last)

marks = [90,25,67,45,80]
number = 0
for marks in marks:
    number+=1
    if marks >= 60:
        print("number:{0} you're in".format(number))
    else:
        #print("number:{0} sorry...".format(number))
        pass

for i in range(2,10):
    for j in range(1,10):
        print(i*j,end= " ")
    print(' ')
a = [1,2,3,4,5,6,7]
result = [num*3 for num in a]
print(result)