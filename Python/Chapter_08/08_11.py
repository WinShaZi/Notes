def Great(arr):
    for item in arr:
        arr[arr.index(item)] += " the Great"


arr1 = ['1', '2', '3']
arr2 = ['1', '2', '3']

Great(arr1)
print(arr1)
Great(arr2[:])
print(arr2)
