import json

map = {
    'name': 'ShaZi',
    'age': 1,
    'height': '***',
    'hobby': [
        'yuri',
        'yuri',
        'yuri'
    ],
    'man': True,
    'secret': None,
    'other': {
        'education': 'undergraduate',
        'profession': '***'
    }
}

# python结构转换为json
jsonStruct = json.dumps(map)
print(jsonStruct)

# json结构转换为python
data = json.loads(jsonStruct)
print(data)

# 写入json
with open('temp.json', 'w+') as file:
    json.dump(map, file)

# 读取json
with open('temp.json', 'r') as file:
    data = json.load(file)
    print(data)
