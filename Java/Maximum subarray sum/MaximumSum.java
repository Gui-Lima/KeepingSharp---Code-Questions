    /*
        They way to do this question is with divide and conquer approach.
        Similar to a mergeSort, first we call splitAndReturnMaximum function
        to split and then check who is higher: 
        .The sum on the left
        .The sum on the right
        .A sum that crosses the middle

        We do that recursively, returning when there is only one number, the number itself.
        The crossing function handles the last case, where we have to go get the highest sum from the middle to the left
        and then the highest sum from the middle to the right
        and that's the highest sum crossing the middle.
    */

    static int maxArraySumWithNegative(int[] arr){
        //corner cases
        if(arr.length == 0){
            return 0;
        }
        int sum = splitAndReturnMaximum(arr, 0, arr.length-1);
        //all negative array
        if(sum < 0){
            return 0;
        }
        return sum;
    }


    static int splitAndReturnMaximum(int arr[], int begin, int end) {
        if (begin == end)
            return arr[begin];

        int m = (begin + end)/2;
        return Math.max(Math.max(
                splitAndReturnMaximum(arr, begin, m),
                splitAndReturnMaximum(arr, m+1, end)),
                maxCrossingSum(arr, begin, m, end));
    }

    static int maxCrossingSum(int arr[], int begin, int mid, int end) {
        int temporarySum = 0;

        int leftSum = Integer.MIN_VALUE;
        for (int i = mid; i >= begin; i--) {
            temporarySum = temporarySum + arr[i];
            if (temporarySum > leftSum)
                leftSum = temporarySum;
        }

        temporarySum = 0;
        int rightSum = Integer.MIN_VALUE;
        for (int i = mid + 1; i <= end; i++) {
            temporarySum = temporarySum + arr[i];
            if (temporarySum > rightSum)
                rightSum = temporarySum;
        }

        return leftSum + rightSum;
    }