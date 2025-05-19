d = {}
ans = ""

for i in range(36):
    s = str(input())
    d[s[:2]] = s[-1]

_ = input()

for i in range(22):
    s = str(input())
    for j in range(0, len(s), 2):
        ans += d[s[j:j + 2]]

print(ans)
