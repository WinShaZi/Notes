import time
import calendar

print('Now time : {:f}'.format(time.time()))
print('Local time : ', time.localtime(time.time()))
print('Local time : ', time.asctime(time.localtime(time.time())))
print('Local time : ', time.strftime('%Y-%m-%d %H:%M:%S', time.localtime()))

print('2020-1 :')
print(calendar.month(2020, 1))

# 包含睡眠时间
start = time.perf_counter()
time.sleep(1.5)
end = time.perf_counter()
print('{:f} - {:f} = {:f}'.format(end, start, end - start))

# 不包含睡眠时间
start = time.process_time()
time = time.sleep(1.5)
end = time.process_time()
print('{:f} - {:f} = {:f}'.format(end, start, end - start))
