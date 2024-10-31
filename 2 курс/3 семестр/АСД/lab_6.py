import numpy as np

l = np.random.randint(0, 1000, 500)

for i in range(len(l)-1):

    min = i

    for j in range(i+1, len(l)):

        if l[j] < l[min]: min = j

    l[i], l[min] = l[min], l[i]

print(l)