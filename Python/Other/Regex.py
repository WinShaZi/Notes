import re

# 修饰符
# re.I      忽略大小写
# re.L      本地化识别
# re.M      多行匹配
# re.S      使.匹配所有字符
# re.U      依据Unicode解析字符
# re.X      正则表达式书写更灵活

sourceStr = '2020-10-10 12:30:45'

# 正则表达式对象
normal_pattern = re.compile(r'([\d]+)-([\d]+)-([\d]+)')
other_pattern = re.compile(r'(?P<first>[\d]+)-(?P<second>[\d]+)-(?P<third>[\d]+)')

# 从开头开始搜索
matchs = re.match(normal_pattern, sourceStr)
# 输出匹配的全部内容
print('matchs.group()   : ' + str(matchs.group()))
# 输出匹配的第一组
print('matchs.group(1)  : ' + str(matchs.group(1)))
# 输出匹配的全部内容按分组来
print('matchs.groups()  : ' + str(matchs.groups()))
# 输入匹配的起始和结束位置组成的元组
print('matchs.span()    : ' + str(matchs.span()))
# 输出匹配起始位置
print('matchs.start()   : ' + str(matchs.start()))
# 输出匹配结束位置
print('matchs.end()     : ' + str(matchs.end()))

# 搜索整个字符串
matchs = re.search(other_pattern, sourceStr)
# 返回组别名和组内容组成的字典
print('matchs.groupdict()   : ' + str(matchs.groupdict()))

# 搜索整个字符串，返回列表
arr = re.findall(normal_pattern, sourceStr)
print('re.findall()         : ' + str(arr))

# 分割字符串
# 按照匹配的内容作为分隔符
arr = re.split(r'[- :]+', sourceStr)
print('re.split()           : ' + str(arr))

# 替换字符串
# 将前三组倒过来
strSub = re.sub(normal_pattern, r'\3-\2-\1', sourceStr)
print('re.sub()             : ' + strSub)
