#Problem:
#for the result is very big; although in python the big data is allow, but how to implement without the language property


#Solution:
#use the arr to store every digit value; and simulate the process of the small data digit

def mul(arr, value):
	carry = 0
	for i in range(len(arr)):
		tmp = arr[i] * value + carry 
		arr[i] = tmp % 10
		carry = tmp / 10
	while carry != 0:
		tmp = carry % 10
		arr.append(tmp)
		carry /= 10

def arr2str(arr):
	rsl = ''
	for value in arr[::-1]:
		rsl += str(value)
	return rsl

def big_factorial(n):
	rsl = [1]
	for i in range(2, n+1):
		mul(rsl, i)

	rsl_value = arr2str(rsl)
	return rsl_value

#test
n = 30
print big_factorial(n)