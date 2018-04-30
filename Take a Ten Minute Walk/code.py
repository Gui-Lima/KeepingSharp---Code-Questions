def isValidWalk(walk):
    length = len(walk)
    horizontal = 0
    vertical = 0
    for i in range(length):
        if walk[i] == 'e':
            horizontal = horizontal + 1
        if walk[i] == 'w':
            horizontal = horizontal - 1
        if walk[i] == 'n':
            vertical = vertical + 1
        if walk[i] == 's':
            vertical = vertical -1
    
    if length == 10 and horizontal == 0 and vertical == 0:
        return True
    else:
        return False
    