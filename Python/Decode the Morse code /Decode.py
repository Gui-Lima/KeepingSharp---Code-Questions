def decodeMorse(morse_code):
    # ToDo: Accept dots, dashes and spaces, return human-readable message
    result = morse_code.split("   ")
    flag = False
    print(result[0])
    endResult = ""
    for i in range(len(result)):
        aux = result[i].split(" ")
        print(aux[0])
        for j in range(len(aux)):
            if aux[j] is not '':
                endResult += MORSE_CODE[aux[j]]
                flag = True
        if flag:
            endResult += " "
        flag = False
    endResult = endResult[:-1]
    return endResult