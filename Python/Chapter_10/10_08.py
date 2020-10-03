try:
    file = open('data')
except FileNotFoundError:
    print('File not found')
else:
    print(file.readlines())
    file.close()
