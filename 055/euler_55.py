def reverse(x):
    return int(str(x)[::-1])

def is_palindrome(x):
    return x == reverse(x)

def is_lycherel(x, limit=50):
    if limit == 0:
        return True
    l = x + reverse(x)
    if is_palindrome(l):
        return False
    return is_lycherel(l, limit-1)

result = len(list(filter(is_lycherel, range(10001))))
print(result)
