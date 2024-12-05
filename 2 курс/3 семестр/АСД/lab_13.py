class HashTable:

    def __init__ (self, size):
        
        self.size = size
        self.table = [None] * size

    def hash_func(self, key):

        return sum(ord(char) for char in key) % self.size
    
    def linear_probing(self, key, value): # Линейное пробирование, квадратичное пробирование или метод двойного хеширования

        idx = self.hash_func(key)
        original_idx = idx

        while self.table[idx] is not None:

            if self.table[idx][0] == key:

                self.table[idx] = (key, value)
                return
            
            idx = (idx + 1) % self.size

            if idx == original_idx: raise Exception('Хеш-таблица переполнена') # Начальная позиция

        self.table[idx] = (key, value)

    def get(self, key):

        idx = self.hash_func(key)
        original_idx = idx

        while self.table[idx] is not None:

            if self.table[idx][0] == key: return self.table[idx][1]

            idx = (idx + 1) % self.size

            if idx == original_idx: break

        return None
    
    def display(self):

        for i, entry in enumerate(self.table): print(f'Index {i}: {entry}')

file_path = "input.txt"

try:
    with open(file_path, "r", encoding="utf-8") as file:
        text = file.read()
except FileNotFoundError:
    print("Файл не найден. Проверьте путь к файлу.")
    exit()

words = text.split()

hash_table = HashTable(size=1000)

for word in words:

    if hash_table.get(word) is None: hash_table.linear_probing(word, 1)

    else:

        count = hash_table.get(word)
        hash_table.linear_probing(word, count + 1)

with open('output.txt', "w", encoding="utf-8") as file:
    for i, entry in enumerate(hash_table.table):
        if entry is not None:
            file.write(f'Index {i}: {entry}\n')