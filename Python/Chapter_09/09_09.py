class Car():
    def __init__(self, power=0):
        self.__power = power

    def AddPower(self, power):
        self.__power += power

    def ConsumePower(self, power):
        self.__power -= power

    def GetPower(self):
        return self.__power


class ElectricCar(Car):
    def __init__(self, electric):
        super().__init__(electric)


electricCar = ElectricCar(100)
electricCar.AddPower(200)
electricCar.ConsumePower(100)
print(electricCar.GetPower())
