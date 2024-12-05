import heapq
import os

# Параметры
CHUNK_SIZE = 100  # Максимальный размер блока, который можно загрузить в память

def split_file(input_file, chunk_size):
    # Разделяет файл на отсортированные блоки.
    chunks = []
    with open(input_file, 'r') as f:
        chunk = []
        for line in f:
            chunk.append(int(line.strip()))
            if len(chunk) >= chunk_size:
                chunk.sort()
                chunk_file = f'chunk_{len(chunks)}.txt'
                with open(chunk_file, 'w') as cf:
                    cf.write('\n'.join(map(str, chunk)))
                chunks.append(chunk_file)
                chunk = []

        # Сортируем и сохраняем оставшиеся данные
        if chunk:
            chunk.sort()
            chunk_file = f'chunk_{len(chunks)}.txt'
            with open(chunk_file, 'w') as cf:
                cf.write('\n'.join(map(str, chunk)))
            chunks.append(chunk_file)

    return chunks

def merge_files(chunks, output_file):
    # Сливает отсортированные блоки в один файл.
    open_files = [open(chunk, 'r') for chunk in chunks]
    heap = []

    # Инициализируем кучу первым элементом из каждого блока
    for i, f in enumerate(open_files):
        line = f.readline()
        if line:
            heapq.heappush(heap, (int(line.strip()), i))

    with open(output_file, 'w') as out:
        while heap:
            value, i = heapq.heappop(heap)
            out.write(f"{value}\n")

            # Считываем следующий элемент из того же блока
            next_line = open_files[i].readline()
            if next_line:
                heapq.heappush(heap, (int(next_line.strip()), i))

    # Закрываем временные файлы
    for f in open_files:
        f.close()

    # Удаляем временные файлы
    for chunk in chunks:
        os.remove(chunk)

input_file = "input.txt"  # Входной файл с данными (по одному числу на строку)
output_file = "sorted_output.txt"  # Имя выходного файла

chunks = split_file(input_file, CHUNK_SIZE)

merge_files(chunks, output_file)

print(f"Файл успешно отсортирован. Результат записан в {output_file}.")
