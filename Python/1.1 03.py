a=input().split()
b=0
while b<3:
    leng=8-len(a[b])
    if leng>0:
        while leng>0:
            print(' ',end='')
            leng-=1
    print(a[b],end=' ')
    #print(' ',end='')
    b+=1
