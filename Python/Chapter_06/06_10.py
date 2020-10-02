map = {
    'A': [1, 2, 3],
    'B': [4, 5, 6],
    'C': [7, 8, 9]
}

for k, v in map.items():
    print(k)
    for i in v:
        print(i, end=' ')
    print()
