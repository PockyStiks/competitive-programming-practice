u = 53
n = 21

for i in range(n):
	b1 = bin(u)[2:]

	counter = 0
	for c in b1:
		if c == '1':
			counter += 1

	b2 = bin(counter)[2:]
	u = int(b1 + b2, 2)

print(u)
