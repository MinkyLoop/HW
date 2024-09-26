def numb(x):

    numbers = set()

    k = 0

    while 3**k <= x:
        
        l = 0

        while 3**k * 5**l <= x:
            
            m = 0

            while 3**k * 5**l * 7 ** m <= x:

                numbers.add(3**k * 5**l * 7 ** m)

                m += 1
            
            l += 1

        k += 1
    
    return sorted(numbers)

x = int(input('Введите x: '))

print(numb(x))