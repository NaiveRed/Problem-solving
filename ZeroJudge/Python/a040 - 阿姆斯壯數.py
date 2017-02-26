
def isOk(n):
    copy = n
    sum = 0
    temp = 1
    digit = 0
    while n // temp > 0:
        temp *=10
        digit+=1    
    while n != 0:
        sum+=(n % 10) ** digit
        n//=10
    if sum == copy:
        return True
    else:
        return False

while True:
    try:
        s = input()
        nm = s.split()
        first = True
        for i in range(int(nm[0]),int(nm[1]) + 1):
            if isOk(i):
                if not first:
                    print(' ',end="")
                else :
                    first = False
                print(i,end="")
        if first:
            print("none")
        else:
            print("")
    except:        
        break