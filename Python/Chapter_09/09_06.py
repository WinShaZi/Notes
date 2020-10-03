class Restaurant():
    def __init__(self, msg):
        self.__message = msg

    def Describe(self):
        print(self.__message)


class IceCreamStand(Restaurant):
    def __init__(self, msg, flavors):
        super().__init__('Father -> ' + msg)
        self.__message = 'Son -> ' + msg
        self.__flavors = flavors

    def Describe(self):
        print(self.__message)
        print(self.__flavors)


ice = IceCreamStand('nothing', ['apple', 'banana', 'cherry'])
ice.Describe()
