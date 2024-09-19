def check_all_brackets(s: str) -> bool:

    stack = []
    bracket_map = {')': '(', '}': '{', ']': '['}
    
    for char in s:

        if char in bracket_map.values(): stack.append(char) # если это открывающая скобка 

        elif char in bracket_map:  # если это закрывающая скобка

            if not stack or stack[-1] != bracket_map[char]: return False

            stack.pop()

        else: continue

    return len(stack) == 0

a = str(input('Введите строку: '))

print('Строка существует' if check_all_brackets(a) else 'Строка не существует')