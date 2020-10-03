try:
    file = open('data')
except FileNotFoundError:
    # 啥都不干
    pass
else:
    print(file.readlines())
    file.close()
