def add(a, b):
    return a + b


def mul(a, b):
    return a * b


def sub(a, b):
    return a - b


def int_div(a, b):
    if b != 0:
        return a // b
    else:
        return None


def float_div(a, b):
    if b != 0:
        return a / b
    else:
        return None


def remainder(a, b):
    return a % b


def power(a, b):
    return a ** b
