def intersect(x, y):
    if len(x) > len(y):
        x, y = y, x
    for i, v in enumerate(x):
        if v in y:
            print(i)
            yield v

print(set(intersect(set([1, 2]), set(range(10000)))))

