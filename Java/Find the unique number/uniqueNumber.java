
 public class Kata {
    public static double findUniq(double arr[]) {
        mergeSort(arr);
        if(arr[0] != arr[1]){
            return arr[0];
        }
        else {
            return arr[arr.length - 1];
        }
        
    }

        //This is a plain mergeSort

    public static void mergeSort(double[] arr){
        split(arr, 0, arr.length-1);
    }

    public static void merge(double arr[], int l, int m, int r)
    {
        // Find sizes of two subarrays to be merged
        int n1 = m - l + 1;
        int n2 = r - m;

        /* Create temp arrays */
        double L[] = new double [n1];
        double R[] = new double [n2];

        /*Copy data to temp arrays*/
        for (int i=0; i<n1; ++i)
            L[i] = arr[l + i];
        for (int j=0; j<n2; ++j)
            R[j] = arr[m + 1+ j];


        /* Merge the temp arrays */

        // Initial indexes of first and second subarrays
        int i = 0, j = 0;

        // Initial index of merged subarry array
        int k = l;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        /* Copy remaining elements of L[] if any */
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        /* Copy remaining elements of R[] if any */
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

     public static void split(double arr[], int l, int r)
    {
        if (l < r)
        {
            // Find the middle point
            int m = (l+r)/2;

            // Sort first and second halves
            split(arr, l, m);
            split(arr , m+1, r);

            // Merge the sorted halves
            merge(arr, l, m, r);
        }
    }
}