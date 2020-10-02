arr = [1, 2, 3, 4, 5]
flag = True

while flag:
    if 3 in arr:
        arr.remove(3)
    else:
        flag = False

print(arr)
