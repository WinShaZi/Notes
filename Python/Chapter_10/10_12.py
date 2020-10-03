import json


def GetNum():
    try:
        with open('data.json') as file:
            num = json.load(file)
    except BaseException:
        return None
    else:
        return num


try:
    num = GetNum()
    if num is None:
        num = input('Input a number : ')
        if not num.isdigit():
            raise ValueError('Not a number')
        with open('data.json', 'w+') as file:
            json.dump(num, file)
except BaseException as e:
    print(e)
else:
    print('I know your favorite number! It\'s ' + num)
