mem = [0, 1]
for i in range(2, 10000):
	mem.append(mem[i - 1] + mem[i - 2])
	t = 0
	for c in str(mem[i]):
		t += int(c)

	if t == 61:
		print(mem[i])
		break
