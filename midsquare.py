"""
Created on Fri Apr 12 12:51:10 2019

@author: psp_643a
"""

# midsquare.py

seed_number = int(input("Enter a 4 digit number:\n[####] "))
n = seed_number
vis = set()
c = 0
ans=[]
while n not in vis:
    c += 1
    vis.add(n)
    n = int(str(n * n).zfill(8)[2:6])
    print(c, ":", n)
    ans.append(n);
print("We began with ", seed_number,
      "and have repeated ourselves after ", c, "steps with ", n)
print("Random numbers are: ")
print(ans)