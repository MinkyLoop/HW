def evaluate_expression(expression):

    def precedence(op):

        if op in ('+', '-'): return 1
        if op in ('*', '/'): return 2

        return 0

    def apply_op(operands, operator):

        right = operands.pop()
        left = operands.pop()

        if operator == '+': operands.append(left + right)
        elif operator == '-': operands.append(left - right)
        elif operator == '*': operands.append(left * right)
        else:

            if right == '0': raise ZeroDivisionError('Деление на ноль запрещено')

            operands.append(left / right)

    def process_expression(exp):

        operands = []
        operators = []
        i = 0

        while i < len(exp):

            if exp[i] == ' ': i += 1

            if exp[i].isdigit():

                num = 0

                while i < len(exp) and exp[i].isdigit():

                    num = num * 10 + int(exp[i])
                    i += 1

                operands.append(num)

            elif exp[i] == '(': operators.append(exp[i]); i += 1
            elif exp[i] == ')':

                while (operators and operators[-1] != '('): apply_op(operands, operators.pop())
                operators.pop()
                
                i += 1

            elif exp[i] in '+-*/':

                while (operators and precedence(operators[-1]) >= precedence(exp[i])): apply_op(operands, operators.pop())
                operators.append(exp[i])

                i += 1

            else: raise ValueError(f'Неожиданный символ {exp[i]}')

        while operators: apply_op(operands, operators.pop())

        return operands[0]

    def validate_expression(exp):
        
        balance = 0
        valid_chars = set('0123456789+-*/() ')

        for char in exp:
            
            if char not in valid_chars: raise ValueError(f'Неправильный символ {char}')

            if char == '(': balance += 1
            elif char == ')': balance -= 1

            if balance < 0: raise ValueError('Несовпадающие скобки')

        if balance != 0: raise ValueError('Несовпадающие скобки')

    expr = expression.strip().rstrip('=')
    validate_expression(expr)
    result = process_expression(expr)

    return result

expression = str(input('Введите текст: '))

try: print(f"Результат: {evaluate_expression(expression)}")
except (ValueError, ZeroDivisionError) as e: print(f"Ошибка: {e}")