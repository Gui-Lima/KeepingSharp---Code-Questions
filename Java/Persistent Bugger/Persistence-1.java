public static int persistence(long n) {
    if (n < 10) {
        return 0;
    }
    int resultContador = 1;
    int numberLength = countNumber(n);
    int numbers[] = makeArrayOfDigits(n, numberLength);
    long mult = multiplication(numbers);
    while (mult >= 10) {
        numberLength = countNumber(mult);
        int digits[] = makeArrayOfDigits(mult, numberLength);
        mult = multiplication(digits);
        resultContador++;
    }
    return resultContador;
}

public static long multiplication(int[] digits) {
    long result = 1;
    for (int i = 0; i < digits.length; i++) {
        result *= digits[i];
    }
    return result;
}

public static int[] makeArrayOfDigits(long n, int size) {
    int numbers[] = new int[size];
    long copia = n;
    if (copia < 0) {
        copia = Math.abs(copia);
    }
    int contador = 0;
    while (copia > 0) {
        long digito = copia % 10;
        numbers[contador] = (int) digito;
        contador++;
        copia = copia / 10;
    }
    return numbers;
}

public static int countNumber(long n) {
    if (n < 0) {
        n = Math.abs(n);
    }
    long copia = n;
    int contador = 0;
    while (copia > 0) {
        long digito = copia % 10;
        contador++;
        copia = copia / 10;
    }
    return contador;
}