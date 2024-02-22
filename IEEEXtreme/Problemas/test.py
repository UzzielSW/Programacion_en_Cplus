# a simple parser for python. use get_number() and get_word() to read
import numpy


def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield (number)


input_parser = parser()


def get_word():
    global input_parser
    return next(input_parser)


def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)


class Node:
    def __init__(self, data):
        super(Node, self).__init__()
        self.data = data
        self.der = None
        self.izq = None


def insert_value(raiz, new_value):
    if raiz is None:
        raiz = Node(new_value)

    elif new_value <= raiz.data:
        if raiz.der is None:
            raiz.der = Node(new_value)
        else:
            raiz.der = insert_value(raiz.der, new_value)

    elif new_value > raiz.data:
        if raiz.izq is None:
            raiz.izq = Node(new_value)
        else:
            raiz.izq = insert_value(raiz.izq, new_value)

    return raiz


def print_tree(root, space=0, t=0):
    COUNT = 3

    if root is None:
        return

    space += COUNT

    print_tree(root.izq, space, 1)

    for x in range(COUNT, space):
        print(" ", end="")

    if t == 1:
        print("/ ", root.data)
    elif t == 2:
        print("\\ ", root.data)
    else:
        print(root.data)

    print_tree(root.der, space, 2)


def pre_orden(raiz):
    if not raiz is None:
        print(raiz.data, end=" ")
        pre_orden(raiz.izq)
        pre_orden(raiz.der)
    return


def in_orden(raiz):
    if not raiz is None:
        in_orden(raiz.izq)
        print(raiz.data, end=" ")
        in_orden(raiz.der)
    return


def pos_orden(raiz):
    if not raiz is None:
        pos_orden(raiz.izq)
        pos_orden(raiz.der)
        print(raiz.data, end=" ")
    return


def cal_longitud(raiz, x, longitud=0):

    if not raiz is None:
        longitud += 1

        if x < raiz.data:
            ver = cal_longitud(raiz.izq, x, longitud)
            if (not ver is None):
                longitud = ver

        elif x > raiz.data:
            ver = cal_longitud(raiz.der, x, longitud)
            if (not ver is None):
                longitud = ver

        else:
            return longitud


N = get_number()
tree = None
colec = dict()

elements = numpy.empty(N, dtype=int)

for i in range(N):
    elements[i] = get_number()

for i in elements:
    tree = insert_value(tree, i)

for i in elements:
    colec[i] = cal_longitud(tree, i, 0)

"""
arr = colec.values()

for i in arr:
    print(i,end=" ")
"""
print_tree(tree)
