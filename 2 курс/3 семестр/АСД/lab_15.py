class TreeNode:

    def __init__(self, value):

        self.left = None
        self.right = None
        self.value = value
    
    def inorder_traversal(self): # Лево, корень, право
        
        result = []
         
        if self.left: result.extend(self.left.inorder_traversal())

        result.append(self.value)

        if self.right: result.extend(self.right.inorder_traversal())

        return result

    def preorder_traversal(self): # Корень, лево, право
        
        result = [self.value]

        if self.left: result.extend(self.left.preorder_traversal())
        if self.right: result.extend(self.right.preorder_traversal())

        return result

    def postorder_traversal(self): # Лево, право, корень
        
        result = []

        if self.left: result.extend(self.left.postorder_traversal())
        if self.right: result.extend(self.right.postorder_traversal())

        result.append(self.value)

        return result


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

print("Прямой обход (Pre-order):", tree.preorder_traversal())
print("Центральный обход (In-order):", tree.inorder_traversal())
print("Концевой обход (Post-order):", tree.postorder_traversal())