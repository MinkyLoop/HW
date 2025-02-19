from functools import lru_cache

def count_shortest_paths(n, m):
    if n == 0 or m == 0:
        return 1
    return count_shortest_paths(n - 1, m) + count_shortest_paths(n, m - 1)

@lru_cache(None)
def count_paths_no_consecutive_vertical(n, m, last_vertical=False):
    if n == 0 and m == 0:
        return 1
    
    paths = 0
    if n > 0:
        paths += count_paths_no_consecutive_vertical(n - 1, m, False)
    if m > 0 and not last_vertical:
        paths += count_paths_no_consecutive_vertical(n, m - 1, True)
    
    return paths

n, m = 18, 18
print("Количество кратчайших путей:", count_shortest_paths(n, m))
print("Количество кратчайших путей без подряд идущих вертикальных участков:", count_paths_no_consecutive_vertical(n, m))
