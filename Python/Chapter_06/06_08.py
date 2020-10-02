map1 = {'11': '11', '12': '12', '13': '13'}
map2 = {'22': '22', '23': '23', '24': '24'}
map3 = {'33': '33', '34': '34', '35': '35'}
arr = [map1, map2, map3]

for map in arr:
    for k, v in map.items():
        print(str(k) + ' : ' + str(v))
