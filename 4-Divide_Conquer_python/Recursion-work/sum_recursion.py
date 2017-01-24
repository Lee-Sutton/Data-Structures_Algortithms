def listsum(num_list):
	if len(num_list) == 1:
		return num_list[0]
	else:
		return num_list[0] + listsum(num_list[1:])

def factorial(number):
	if number <= 1:
		return number

	else:
		return number*factorial(number - 1)

print factorial(3)