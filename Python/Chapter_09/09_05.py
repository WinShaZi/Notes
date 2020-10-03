class User():
    def __init__(self):
        self.__loginNum = 0

    def Increment(self):
        self.__loginNum += 1

    def Reset(self):
        self.__loginNum = 0

    def Show(self):
        print(self.__loginNum)


res = User()
res.Increment()
res.Reset()
res.Increment()
res.Show()
