def Profile(name, **info):
    map = {'name': name}
    for k, v in info.items():
        map[k] = v
    return map


print(Profile('ShaZi', tall='no', rich='no', handsome='no'))
