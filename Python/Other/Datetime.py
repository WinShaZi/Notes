import time
import datetime
import calendar


# 当前时间以秒的形式
print('Now time : {:f}'.format(time.time()))
# 本地时间以元组形式
print('Local time : ', time.localtime(time.time()))
# 本地时间
print('Local time : ', time.asctime(time.localtime(time.time())))
# 格式化本地时间
print('Local time : ', time.strftime('%Y-%m-%d %H:%M:%S', time.localtime()))

# 获取当前日期和时间
beg = datetime.datetime.now()
print('beg : ' + str(beg))
time.sleep(2)
end = datetime.datetime.now()
print('end : ' + str(end))

# datetime转str
strBeg = beg.strftime('%Y-%m-%d %H:%M:%S')
strEnd = end.strftime('%Y-%m-%d %H:%M:%S')
# str转datetime
beg = datetime.datetime.strptime(strBeg, '%Y-%m-%d %H:%M:%S')
end = datetime.datetime.strptime(strEnd, '%Y-%m-%d %H:%M:%S')
# 二者时间间隔，只返回秒部
print('seconds : {:d}'.format(int((end - beg).seconds)))

# 字符串时间转换为秒
secBeg = time.mktime(time.strptime(strBeg, "%Y-%m-%d %H:%M:%S"))
secEnd = time.mktime(time.strptime(strEnd, "%Y-%m-%d %H:%M:%S"))
print('seconds : {:d}'.format(int(secEnd - secBeg)))

# 获取日历
print('2020-1 :')
print(calendar.month(2020, 1))

# 包含睡眠时间
start = time.perf_counter()
time.sleep(1.5)
end = time.perf_counter()
print('{:f} - {:f} = {:f}'.format(end, start, end - start))

# 不包含睡眠时间
start = time.process_time()
time.sleep(1.5)
end = time.process_time()
print('{:f} - {:f} = {:f}'.format(end, start, end - start))
