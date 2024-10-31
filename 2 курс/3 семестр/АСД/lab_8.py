import numpy as np

l = np.random.randint(1, 100, 200)
max_digital = max([len(str(x)) for x in l])
last = [[] for i in range(10)]

for i in range(max_digital):
    
    for num in l:

        digit = (num // 10**i)%10
        last[digit].append(num)

    l = [i for j in last for i in j]
    
    last = [[] for i in range(10)]

print(l)