a, b = input('Input a b : ').split()
while a != 'q' and b != 'q':
    try:
        a = int(a)
        b = int(b)
    except ValueError as e:
        print(e)
    else:
        print(str(a + b))
    finally:
        a, b = input('Input a b : ').split()
