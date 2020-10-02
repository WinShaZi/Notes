def Great(arr):
    for item in arr:
        arr[arr.index(item)] += " the Great"


arr = ['1', '2', '3']

Great(arr)
print(arr)
