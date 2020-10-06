# 事件

import threading
import time


event = threading.Event()


def Light():
    while True:
        if int(time.time()) % 10 in range(0, 4):
            if not event.is_set():
                print('Light is red')
                event.set()
        else:
            if event.is_set():
                print('Light is green')
                event.clear()
        time.sleep(1)


def Car():
    while True:
        if not event.is_set():
            print('Car run')
        # set之后不阻塞，非clear之后阻塞
        event.wait()
        print('Car stop')
        time.sleep(1)


t1 = threading.Thread(target=Light, args=())
t2 = threading.Thread(target=Car, args=())

t1.start()
t2.start()
