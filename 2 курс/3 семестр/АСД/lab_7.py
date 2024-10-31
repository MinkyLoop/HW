import numpy as np

l = np.random.randint(1, 100, 200)

step = len(l) // 2

while step > 0:

    for i in range(step, len(l)):

        j = i

        while j - step >= 0 and l[j] < l[j - step]:

            l[j], l[j - step] = l[j - step], l[j]
            j -= step

    step //= 2

print(l)