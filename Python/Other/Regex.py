import re


def ShowResult(result):
    if result is not None:
        if type(result) is list:
            print(result)
        elif type(result) is str:
            print(result)
        else:
            print(result.group())
    else:
        print(None)


sourceStr = 'To be or not to be, that is the question'

# 修饰符
# re.I      忽略大小写
# re.L      本地化识别
# re.M      多行匹配
# re.S      使.匹配所有字符
# re.U      依据Unicode解析字符
# re.X      正则表达式书写更灵活

# 正则表达式对象
pattern = re.compile('([a-z])+ ([a-z])+', re.I)

# 从开头开始搜索
ShowResult(re.match(pattern, sourceStr))

# 搜索整个字符串
ShowResult(re.search(pattern, sourceStr))

# 搜索整个字符串，返回列表
ShowResult(re.findall(pattern, sourceStr))

# 分割字符串
ShowResult(re.split(pattern, sourceStr))

# 替换字符串
ShowResult(re.sub(pattern, 'NONE', sourceStr))
