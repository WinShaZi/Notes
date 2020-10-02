arr = ('A', 'B', 'C', 'D', 'E')
map = {'A': 'a', 'B': 'b', 'C': 'c'}

for item in arr:
    if item in map.keys():
        print('Thinks ' + item)
    else:
        print('Come here ' + item)
