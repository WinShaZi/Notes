import unittest


def Place(city, country, population):
    return city.title() + ', ' + country.title() + ' - ' + population.title()


class TestClass(unittest.TestCase):
    def test_Func(self):
        place = Place('wuhan', 'china', '14000')
        self.assertEqual(place, 'Wuhan, China - 14000')


unittest.main()
