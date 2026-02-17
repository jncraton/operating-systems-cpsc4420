def square(n):
    return n*n

#print([square(n) for n in range(1,21)])

print(list(map(square, range(1, 21))))