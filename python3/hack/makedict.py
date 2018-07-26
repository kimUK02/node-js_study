from itertools import product 
from threading import Thread,Lock
lock = Lock()
def main():
    ch_table = range(33, 127)
    lock.acquire()
    with open('allpermutate.txt', 'w') as file:
        try:
            r = ''
            for i in range(4, 12):
                for p in product(ch_table,repeat=i):
                    for c in p:
                        r += chr(c)
                    file.write(r)
                    file.write('\n')
                    print('[+] Generated :', r)
                    r = ''
        finally:
            lock.release()

t = Thread(target=main,args=(1,10))
t.start()
if __name__ == '__main__':
    main()

