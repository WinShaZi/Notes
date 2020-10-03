class User():
    def __init__(self, privileges):
        self.__privileges = privileges
        self.__pvTable = ('can add post', 'can delete post', 'can ban user')
        self.__pvMap = {
            0: (),
            1: self.__pvTable[:1],
            2: self.__pvTable[1:2],
            3: self.__pvTable[:2],
            4: self.__pvTable[-1:],
            5: (self.__pvTable[0], self.__pvTable[2]),
            6: self.__pvTable[1:],
            7: self.__pvTable[:]
        }

    def Privileges(self):
        print(self.__pvMap[self.__privileges])


class Admin(User):
    def __init__(self, privileges):
        super().__init__(privileges)


for i in range(0, 8):
    admin = Admin(i)
    admin.Privileges()
