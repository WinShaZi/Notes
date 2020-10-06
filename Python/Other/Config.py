import configparser
import os
import sys
import time


# config.ini
'''
[anime]
yuri = best
funny = better
truelove = good
harem = kill
ntr = destroy

[infomation]
name = ShaZi
age = 1
weight = 55.5
'''

config = configparser.ConfigParser()

config.read('config.ini')

for section in config.sections():
    for item in config.items(section):
        print('s -> i ==> {:s} -> {:s}'.format(str(section), str(item)))
    for option in config.options(section):
        print('s -> o ==> {:s} -> {:s}'.format(str(section), str(option)))
        print('s -> o -> v ==> {:s} -> {:s} -> {:s}'.format(str(section), str(option), str(config.get(section, option))))


# 获取整形，浮点，布尔值
# config.getint(section, option)
# config.getfloat(section, option)
# config.getboolean(section, option)

config.remove_option('infomation', 'name')
config.remove_section('infomation')

config.add_section('temp')
config.set('temp', 'filename', os.path.basename(sys.argv[0]))
config.set('temp', 'time', str(time.time()))

with open('config.ini', 'w') as file:
    config.write(file)
