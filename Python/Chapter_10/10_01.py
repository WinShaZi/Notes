with open('data', encoding='UTF-8') as file:
    data = file.read()
    print(data)

with open('data', encoding='UTF-8') as file:
    for line in file:
        print(line.rstrip())

with open('data', encoding='UTF-8') as file:
    lines = file.readlines()
    print(lines)
