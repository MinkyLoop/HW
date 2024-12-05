class HashTable:

    def __init__(self, size):

        self.size = size
        self.table = [[] for _ in range(size)]

    def hash_func(self, key):

        return sum(ord(char) for char in key) % self.size
    
    def insert(self, key):

        idx = self.hash_func(key)
        self.table[idx].append(key)
    
    def __str__(self):

        result = ''

        for i, chain in enumerate(self.table): result += f'Index {i}: {chain}\n'

        return result
    
try: 
    
    with open('input.txt', 'r', encoding='utf-8') as file: text = file.read()

except FileNotFoundError:

    print('Файл не найден. Проверьте путь к файлу.')
    exit()

words = text.split()

hash_table = HashTable(100)

for word in words: hash_table.insert(word)

with open('output.txt', 'w', encoding='utf-8') as file:

    for i, entry in enumerate(hash_table.table):

        if entry is not None:
            
            file.write(f'Index {i}: {entry}\n')