a=int(input())
if a<=150:
    b=a*0.4463
    print('%.1f'%b)
elif a<=400:
    b=150*0.4463
    b+=(a-150)*0.4663
    print('%.1f'%b)
else :
    b=150*0.4463
    b+=250*0.4663
    b+=(a-400)*0.5663
    print('%.1f'%b)
