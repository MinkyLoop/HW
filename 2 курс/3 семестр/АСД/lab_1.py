x = str(input('Введите строку'))

x = x.replace('(', '1')
x = x.replace('[', '2')
x = x.replace('{', '3')
x = x.replace(')', '4')
x = x.replace(']', '5')
x = x.replace('}', '6')

def fun(a, b):

    if len(a) == 2 and (int(a[1]) - int(a[0])) == 3: return "Строка существует"
    
    try:

        if a[b] in '123': return fun(a, b+1)

        elif int(a[b])-int(a[b-1]) == 3:

            a = a[0:b-1] + a[b+1:len(a)]

            return fun(a, b-1)
        
        else: return "Строки не существует"

    except(ValueError):

        return "Строки не существует"
    
print(fun(x,0))