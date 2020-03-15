# -*- coding: utf-8 -*-
import math
year,month,day = map(int,input().split())
date = ["Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"]
month1= [1,3,5,7,8,10,12]
month0= [4,6,9,11]
q=0
m=0
if month in month1 :
    q=31
elif month in month0 :
    q=30
else :
    year-=1
    if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0) :
        q=29
    else :
        q=28
if month == 1 or month == 2:
    m=month+12
if month == 1 :
    year-=1
j=math.floor(year/100)
k=year%100
h=(q+math.floor(26*(m+1)/10)+k+math.floor(k/4)+math.floor(j/4)+5*j)%7
print(h)
print(date[h])


