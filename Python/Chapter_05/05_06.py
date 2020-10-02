for age in range(0, 70):
    if age < 2:
        print('baby')
    elif age >= 2 and age < 4:
        print('young child')
    elif age >= 4 and age < 13:
        print('child')
    elif age >= 13 and age < 20:
        print('teenager')
    elif age >= 20 and age < 65:
        print('man')
    else:
        print('old man')
