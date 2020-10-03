import unittest


class Employee():
    def __init__(self, name, age, salary):
        self.name = name
        self.age = age
        self.salary = salary

    def UpSalary(self):
        self.salary += 5000


class TestClass(unittest.TestCase):
    def setUp(self):
        self.shaZi = Employee('ShaZi', 22, 10000)

    def test_UpSalary(self):
        self.shaZi.UpSalary()
        self.assertEqual(15000, self.shaZi.salary)


unittest.main()
