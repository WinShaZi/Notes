username = ['A', 'B', 'C', 'D', 'E']
signIn = ['b', 'f']

for item in signIn:
    if item.upper() in username:
        print('exists')
    else:
        print('success')
