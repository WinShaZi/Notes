# 指定参数类型和返回值类型
def Func(i: int, d: float, map: {}) -> str:
    print(i, d, map)
    return 'Hello World'


print(Func(10, 10.0, {'a': 'A', 'b': 'B'}))
