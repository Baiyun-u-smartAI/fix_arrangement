# -*- coding: utf-8 -*-
def two_in_one(b,c):
    a=[]
    while (len(b)!=0)& (len(c)!=0):

        if (b[0]<c[0]) :
            a.append(b.pop(0))
        else:
            a.append(c.pop(0))
    return a+b+c

def to_apart(a):
    b=[]
    len_b=len(a)/2
    while len(b)!=len_b:
        b.append(a.pop(0))
    return b,a

def fix_arrange(a):
    for i in range(0,len(a)-1):
        for j in range(i,len(a)):
            if a[i]>a[j]:
                a[i],a[j] = a[j],a[i]
    return a

if __name__ ==  "__main__":
    a=[5,7,34,8,1]
    b,c=to_apart(a)
    b=fix_arrange(b)
    c=fix_arrange(c)
    print two_in_one(b,c)