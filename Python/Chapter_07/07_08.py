arr = [1, 2, 3]
temp = []

while len(arr) > 0:
    temp.insert(0, arr[-1])
    arr.pop()

print(arr)
print(temp)
