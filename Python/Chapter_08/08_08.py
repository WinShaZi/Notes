def Album(author, title):
    return {author: title}


map = {}
author = input('Author : ')
while author != '':
    title = input('Title : ')
    for k, v in Album(author, title).items():
        map[k] = v
    author = input('Author : ')

print(map)
