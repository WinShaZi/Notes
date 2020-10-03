import unittest


def Place(city, country):
    return city.title() + ', ' + country.title()


class TestClass(unittest.TestCase):
    # 测试函数必须以test开头
    def test_Func(self):
        place = Place('wuhan', 'china')
        self.assertEqual(place, 'Wuhan, China')


unittest.main()
