def valid_parentheses(string):
    stack = []
    for i in range(len(string)):
        if string[i] == "(":
            stack.append("(")
        if string[i] == ")":
            if not stack:
                return False
            stack.pop()
    if not stack:
        return True
    else:
        return False