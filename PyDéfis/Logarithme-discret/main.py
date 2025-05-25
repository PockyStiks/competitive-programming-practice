nums = [50, 36, 153, 128, 71, 23, 75, 55, 208, 121]
ans = []
for b in nums:
    x = 0
    while True:
        if 3**x % 223 == b:
            ans.append(x)
            break
        x += 1
print(ans)
    
