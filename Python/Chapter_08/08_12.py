# 参数数量不确定，参数为元组
def Food(*argv):
    print(argv)


Food('1')
Food(1, '2')
Food(1, 2, 3)
