try:
    num = 0
    with open('data') as file:
        for line in file:
            num += line.lower().count('the')
except FileNotFoundError as e:
    print(e)
else:
    print(num)
