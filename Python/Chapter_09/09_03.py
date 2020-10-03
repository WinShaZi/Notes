class User():
    def __init__(self, name):
        self.__name = name

    def Describe(self):
        print(self.__name)

    def Greet(self):
        print('Hello ' + self.__name)


user = User('ShaZi')
user.Describe()
user.Greet()
