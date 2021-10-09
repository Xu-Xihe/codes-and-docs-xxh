a=int(input())
b=0
i=1
j=1
while i<=a:
    j=1
    c=1
    while j<=i:
        c*=j
        j+=1
    b+=c
    i+=1
print(b)
