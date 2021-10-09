ina=int(input())
n=1
z=0
while 1:
    z+=1/n
    if z>ina:
        print(n)
        exit()
    n+=1 
