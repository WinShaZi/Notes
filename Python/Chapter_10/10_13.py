import json


def GetUsers():
    try:
        with open('data.json') as file:
            users = json.load(file)
    except BaseException:
        return None
    else:
        return users


try:
    username = input('Input : ')
    users = GetUsers()
    while username != 'quit' and username not in users:
        username = input('Input : ')
except BaseException as e:
    print(e)
else:
    print('Hello ' + username)
