from turtle import left
import numpy as np

def merge(arr1, arr2):

    arr = []

    while len(arr1) and len(arr2):

        if arr1[0] < arr2[0]: arr.append(arr1.pop(0))
        else: arr.append(arr2.pop(0))

    if len(arr1): arr.append(arr1.pop())
    if len(arr2): arr.append(arr2.pop())

    return arr

def merge_sort(arr):

    if len(arr) < 2: return arr

    return merge(merge_sort(arr[:int(len(arr) / 2)]), merge_sort(arr[int(len(arr) / 2):]))

arr = list(np.random.randint(1, 100, 100))

print(merge_sort(arr))