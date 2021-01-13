# 全局变量

import threading

g_value = 0


def Run(label, n):
    # 当外部变量需要在内部进行操作时，需要声明为global
    global g_value
    i = 0
    while i < n:
        g_value += 1
        i += 1
    print(label + ' ' + str(g_value))


t1 = threading.Thread(target=Run, args=('t1', 300000, ))
t2 = threading.Thread(target=Run, args=('t2', 500000, ))

t1.start()
t2.start()
