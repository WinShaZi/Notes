with open('data', 'a+', encoding='UTF-8') as file:
    name = input('Input your name : ')
    while name != 'quit':
        print('Hello ' + name)
        file.write(name + '\n')
        name = input('Input your name : ')
