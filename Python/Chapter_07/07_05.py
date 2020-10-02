message = input('Input your age : ')

while int(message) >= 0:
    if int(message) < 3:
        print('free')
    elif int(message) >= 3 and int(message) < 12:
        print('half')
    else:
        print('complete')
    message = input('Input your age : ')
