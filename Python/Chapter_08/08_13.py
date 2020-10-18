# 参数类型是关键字参数且数量不确定，参数类型为字典
def Profile(name, **info):
    print(name)
    print(info)


Profile('ShaZi', tall='no', rich='no', handsome='no')
