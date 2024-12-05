class TreeNode:

    def __init__(self, value):

        self.value = value
        self.left = None
        self.right = None

def preorder_traversal(root):

    if root is None: return ""
    
    result = []
    stack = [root]
    
    while stack:

        node = stack.pop()
        result.append(str(node.value))  # Сохранение значения узла
        
        # Важно: сначала добавляем в стек правый узел, потом левый,
        # чтобы при следующем извлечении обрабатывался левый узел.
        if node.right: stack.append(node.right)
        if node.left: stack.append(node.left)
    
    return " ".join(result)

def build_tree_from_string(s):
    
    def parse_subtree(s, index):

        if index >= len(s) or s[index] == ')': return None, index

        # Получаем корень поддерева
        value = ''

        while index < len(s) and s[index].isdigit():

            value += s[index]
            index += 1

        if value == '': return None, index

        root = TreeNode(int(value))

        # Если у нас есть поддеревья, обрабатываем их
        if index < len(s) and s[index] == '(':

            index += 1  # Пропускаем открывающую скобку
            root.left, index = parse_subtree(s, index)

            if index < len(s) and s[index] == ',': index += 1  # Пропускаем запятую

            root.right, index = parse_subtree(s, index)
            index += 1  # Пропускаем закрывающую скобку
        
        return root, index

    tree, _ = parse_subtree(s, 0)

    return tree

text = "8(3(1,6(4,7)),10(,14(13,)))"
tree = build_tree_from_string(text)

print(preorder_traversal(tree))