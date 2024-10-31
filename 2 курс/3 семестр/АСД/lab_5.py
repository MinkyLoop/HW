import numpy as np

list = np.random.randint(1, 100, 200)

for i in range(1,len(list)):

    j = i

    while j > 0 and list[j] < list[j - 1]:
    
        list[j], list[j - 1] = list[j - 1],  list[j]
        j -= 1

print(list)