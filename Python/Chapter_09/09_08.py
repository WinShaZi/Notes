class Privileges():
    def __init__(self):
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

    def GetPrivileges(self, pv):
        return self.__pvMap[pv]


class User():
    def __init__(self, pv):
        self.__privileges = Privileges()
        self.__pv = pv

    def Privileges(self):
        print(self.__privileges.GetPrivileges(self.__pv))


class Admin(User):
    def __init__(self, pv):
        super().__init__(pv)


for i in range(0, 8):
    admin = Admin(i)
    admin.Privileges()
