# a simple parser for python. use get_number() and get_word() to read
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


arreglo = []
arr1 = []
arr2 = []

N = get_number()
M = get_number()

if 1 <= N and N <= 10**5:
    if 1 <= M and M <= 10**5:
        if 2 <= (N+M) and (N+M) <= 10**5:

            for i in range(N):
                arr1.append(get_number())

            for i in range(M):
                arr2.append(get_number())

            arreglo += arr1

            arr2 = set(arr2)
            arr2 = list(arr2)
            arr2.sort()

            for i in range(0, len(arr1)+1):
                if not arr2:
                    break
                elif arr2[0] == arreglo[i]-1:
                    arreglo.insert(i, arr2.pop(0))
                elif arr2[0] == arreglo[i]:
                    arr2.pop(0)

            for i in arreglo:
                print(i, end=" ")
