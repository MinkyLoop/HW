import numpy as np

def quick_sort(arr):

    if len(arr) < 2: return arr
    
    pivot = arr.pop() # Правильный выбор опорной точки - сортировка первого, последнего и среднего элемента, и выбор среднего элемента
    left, right = [], []

    for i in arr:

        if pivot > i: left.append(i)
        else: right.append(i)
    
    result = quick_sort(left)
    result.append(pivot)
    result.extend(quick_sort(right))

    return result

arr = list(np.random.randint(1, 100, 100))

print(quick_sort(arr))