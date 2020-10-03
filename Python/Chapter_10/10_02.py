with open('data', encoding='UTF-8') as file:
    for line in file:
        print(line.replace('python', 'cpp').rstrip())
