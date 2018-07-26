import datetime

s = datetime.datetime.now()
s = str(s)+"\n"
f = open("file_io.txt","a")
f.write(s)
for i in range(1,11):
    data = "%d 번째 줄입니다..\n" %i
    f.write(data)
f.close()
