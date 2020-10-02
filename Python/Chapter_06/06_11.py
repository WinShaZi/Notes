map = {
    'A': {'active': 6, 'apply': 5, 'append': 6},
    'B': {'banana': 6, 'by': 2, 'binary': 6},
    'C': {'catch': 5, 'case': 4, 'const': 5}
}

for k1, v1 in map.items():
    print(k1)
    for k2, v2 in v1.items():
        print(k2 + ' : ' + str(v2))
