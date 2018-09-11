def convert(n, base):
    T = "0123456789ABCDEF"
    q, r = divmod(n, base)
    if q == 0:
        return T[r]
    else:
        return convert(q, base) + T[r]
if __name__ == '__main__':
    string = ""
    n = int(input("n:"))
    t = int(input("t:"))
    m = int(input("m:"))
    p = int(input("p:"))
    for i in range(t*2):
        string += str(convert(i,n))
    for j in range(p-1,t*2,m):
        print(string[j],end='')
    