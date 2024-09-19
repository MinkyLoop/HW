import numpy as np
from scipy.stats import multivariate_normal
import time

# 1 задание

text = '''3,4,17,-3
5,11,-1,6
0,2,-5,8'''

with open('matrix.txt', 'w') as file:

    file.write(text)

matrix = np.genfromtxt('matrix.txt', delimiter=',')

print(np.sum(matrix))
print(np.min(matrix))
print(np.max(matrix))

# 2 задание

print(np.unique([2, 2, 2, 3, 3, 3, 5], return_counts=True))

# 3 задание

random_array = np.random.randn(10, 4)

print(np.min(random_array))
print(np.max(random_array))
print(np.mean(random_array))
print(np.std(random_array))

first_five_row = random_array[:5, :]

print(first_five_row)

# 4 задание

x = np.array([6, 2, 0, 3, 0, 0, 5, 7, 0])

zero_indices = np.where(x[:-1] == 0)[0]

print(np.max(x[zero_indices + 1]))

# 5 задание

def log_pdf_multivariate_normal(X, m, C):
    D = m.shape[0]
    det_C = np.linalg.det(C)
    inv_C = np.linalg.inv(C)
    norm_term = -0.5 * D * np.log(2 * np.pi) - 0.5 * np.log(det_C)
    mahalanobis_term = -0.5 * np.sum((X - m) @ inv_C * (X - m), axis=1)
    return norm_term + mahalanobis_term

X = np.random.randn(1000, 3)
m = np.array([0, 0, 0])
C = np.eye(3)

start_time = time.time()
log_pdf_numpy = log_pdf_multivariate_normal(X, m, C)
numpy_execution_time = time.time() - start_time

start_time = time.time()
log_pdf_scipy = multivariate_normal(m, C).logpdf(X)
scipy_execution_time = time.time() - start_time

print("Время выполнения log_pdf_multivariate_normal():", numpy_execution_time)
print("Время выполнения logpdf() из scipy.stats.multivariate_normal:", scipy_execution_time)

# 6 задание

a = np.arange(16).reshape(4,4)

a[[1, 3]] = a[[3, 1]]

print(a)

# 7 задание

url = 'https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data'
iris = np.genfromtxt(url, delimiter=',', dtype='object')

print(np.unique(iris[:, 4], return_counts=True))

# 8 задание

print(np.where(np.array([0,1,2,0,0,4,0,6,9]) != 0)[0])