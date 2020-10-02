arr = []

message = input('Input : ')
while message.lower().strip() != 'quit':
    arr.append(message)
    message = input('Input : ')

print(arr)
