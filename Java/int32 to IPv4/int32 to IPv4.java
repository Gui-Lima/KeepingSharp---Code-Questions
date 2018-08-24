public class Kata {
	
    public static String longToIP(long ip) {
        // Java doesn't have uint32, so here we use long to represent int32
        String binaryRepresentation = Long.toBinaryString(ip);
        binaryRepresentation = fillZeros(binaryRepresentation);
        String octes[] = makeOctes(binaryRepresentation);
        int numbersFormingIp[] = takeNumbersOutOfOctes(octes);
        String result = takeStringFromIntArray(numbersFormingIp);
        System.out.println(result);
        return result; // do it!
    }

    private static String fillZeros(String binaryRepresentation) {
        String result = "";
        for(int i =0;i<32-binaryRepresentation.length();i++){
            result += "0";
        }
        result += binaryRepresentation;
        return result;
    }

    private static String takeStringFromIntArray(int[] numbersFormingIp) {
        String result = "";
        for(int i =0;i<numbersFormingIp.length;i++){
            result += Integer.toString(numbersFormingIp[i]);
            result += ".";
        }
        StringBuilder sb = new StringBuilder(result);
        sb.deleteCharAt(result.length()-1);
        result = sb.toString();
        return result;
    }

    private static int[] takeNumbersOutOfOctes(String[] octes) {
        int numbers[] = new int[4];
        for(int i =0;i<octes.length;i++){
            numbers[i] = makeNumber(octes[i]);
        }
        return numbers;
    }

    private static int makeNumber(String octe) {
        //octe is a binary string of 8 digits
        int result = 0;

        for(int i = 7;i>=0;i--){
            if(octe.charAt(7-i) == '1')
                result += Math.pow(2, i);
        }

        return result;
    }

    private static String[] makeOctes(String binary){
        String octes[] = new String[4];
        for(int i =0;i<octes.length;i++){
            octes[i] = "";
        }
        int numberOfOctes = 4;
        for(int i =1, j =0;i<=8*numberOfOctes;i++){
            octes[j] += binary.charAt(i-1);
            if( i % 8 == 0) {
                j++;
            }
        }
        return octes;
    }
}
