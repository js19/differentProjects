import math

#recursion
def FirstFactorial(num): 
    if num == 1:
        return num
    return num * FirstFactorial(num - 1)
    
def loop(num):
	res = 1
	for i in range(1, num):
		res *= i + 1
	return res

def mathLibrary(num):
	return math.factorial(num)
 
print FirstFactorial(raw_input())