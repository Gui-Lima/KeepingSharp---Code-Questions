def expanded_form(num):
    stringedNumber = str(num)
    result = ""
    for i in range(len(stringedNumber)):
        numberFactorOfTen = int(stringedNumber[i]) * (10 ** (len(stringedNumber) - (i+1)))
        if numberFactorOfTen == 0:
            continue
        result += str(int(stringedNumber[i]) * (10 ** (len(stringedNumber) - (i+1)))) + ' + '
    result = result[:-3]
    return result