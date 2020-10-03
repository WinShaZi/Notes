with open('data', 'a+', encoding='UTF-8') as file:
    message = input('Input : ')
    lines = []
    while message != 'quit':
        lines.append(message + '\n')
        message = input('Input your name : ')
    file.writelines(lines)
