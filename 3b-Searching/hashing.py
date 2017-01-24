def hash(astring, tablesize):
	sum = 0
	for character in range(len(astring)):
		sum = sum + ord(character)

	return sum%tablesize

table = [[],[],[],[],[],[],[],[],[],[],[]]
print len(table)