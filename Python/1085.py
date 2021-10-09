ina=[0]*7
i=0
big=0
ji=-1
while i<7:
    ina[i]=input().split()
    i+=1
i=0
while i<7:
    add=int(ina[i][0])+int(ina[i][1])
    if add>8:
        add-=8
        if add>big:
            big=add
            ji=i+1
    i+=1
if ji>=0:print(ji)
else:print('0')
