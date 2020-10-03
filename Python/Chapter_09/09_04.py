class Restaurant():
    def __init__(self):
        self.__number = 0

    def SetNumber(self, num):
        self.__number = num

    def GetNumber(self):
        return self.__number

    def Increment(self, num):
        self.__number += num


res = Restaurant()
res.SetNumber(10)
res.Increment(10)
print(res.GetNumber())
