class Solution {
      public static String rangeExtraction(int[] arr) {
        String rangeFormat = "";
        for(Integer i = 0;i<arr.length;i++){
            if(i+1 < arr.length && i+2 < arr.length && arr[i+1] == arr[i] + 1 && arr[i+2] == arr[i] + 2){
                int count = 0;
                Integer pastI = i;
                while(i+1 < arr.length && arr[i] + 1 == arr[i+1]){
                    i++;
                }
                rangeFormat += Integer.toString(arr[pastI]) + "-" + Integer.toString(arr[i]) + ",";
                if(i == arr.length-1){
                    rangeFormat = rangeFormat.substring(0, rangeFormat.length()-1);
                }
                continue;
            }
            rangeFormat += Integer.toString(arr[i]) + ",";
            if(i == arr.length-1){
                rangeFormat = rangeFormat.substring(0, rangeFormat.length()-1);
            }
        }
        System.out.println(rangeFormat);
        return rangeFormat;
    }
}