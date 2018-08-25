import string

def is_pangram(s):
    arr = {}
    for i in range(122):
        arr[i] = 0

    for i in range(len(s)):
        print(ord(s[i].lower()))
        arr[ord(s[i].lower())] = 1

    for i in range(122-97):
        if arr[i+97] == 0:
            return False
    return True