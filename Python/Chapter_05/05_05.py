alienColor = ('green', 'yellow', 'red')
killColor = ['red', 'green', 'yellow']

for color in killColor:
    if 'green' == color:
        print('You get five points')
    elif 'yellow' == color:
        print('You get ten points')
    else:
        print('You get fifteen points')
