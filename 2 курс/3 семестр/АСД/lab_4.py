import numpy as np

list = np.random.randint(1, 100, 200)
factor = 1.247 #Фактор уменьшения
gapFactor = len(list)/factor

while gapFactor > 1:

    gap = int(gapFactor)

    for i in range(len(list) - gap):

        if list[i] > list[i + gap]: list[i], list[i + gap] = list[i + gap], list[i]

    gapFactor /= factor

print(list)