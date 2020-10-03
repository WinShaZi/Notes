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


res1 = Restaurant('all right')
res2 = Restaurant('all error')
res3 = Restaurant()
