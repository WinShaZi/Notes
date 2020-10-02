active = True

message = input('Input : ')
while message.lower().strip() != 'quit':
    print(message)
    message = input('Input : ')

message = input('Input : ')
while active:
    if message.lower().strip() == 'quit':
        active = False
        continue
    print(message)
    message = input('Input : ')

message = input('Input : ')
while True:
    if message.lower().strip() == 'quit':
        break
    print(message)
    message = input('Input : ')
