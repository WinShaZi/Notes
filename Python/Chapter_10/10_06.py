try:
    a, b = input('Input a b : ').split()
    a = int(a)
    b = int(b)
except ValueError as e:
    print(e)
else:
    print(str(a + b))
