# __name : 私有变量或方法

class Restaurant():
    def __init__(self, msg='nothing'):
        self.__message = msg
        print('__init__')

    def Open(self):
        print('open')

    def Close(self):
        print('close')

    def Describe(self):
        print(self.__message)


res = Restaurant('all right')
res.Open()
res.Describe()
res.Close()
