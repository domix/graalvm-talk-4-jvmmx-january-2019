import sys

print(sys.version_info)
num = int(sys.argv[1])

factorial = 1

if num < 0:
   print("Invalid number ", num)
elif num == 0:
   print(factorial)
else:
   for i in range(1,num + 1):
       factorial = factorial*i
   #print("The factorial of",num,"is",factorial)
   print(factorial)