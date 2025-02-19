from collections import Counter
from itertools import permutations

def count_unique_words(word, length):
    letter_counts = Counter(word)
    unique_words = set()

    # Перебираем все перестановки длины `length`
    for perm in permutations(word, length):

        perm_counter = Counter(perm)
        # Проверяем, что ни одна буква не выбрана чаще, чем встречается в исходном слове
        if all(perm_counter[letter] <= letter_counts[letter] for letter in perm_counter): unique_words.add(perm)

    return len(unique_words)

word = "КОМБИНАТОРИКА"
length = 5
print("Количество различных слов длины 5:", count_unique_words(word, length))