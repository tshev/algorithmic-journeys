def intersect(x, y):
    if len(x) > len(y): x, y = y, x
    for i, v in enumerate(x):
        if v in y: yield v; print(i);

x, y = set([1, 2]), set(range(10**7))
print(set(intersect(x, y)))

