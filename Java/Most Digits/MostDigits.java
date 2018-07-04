public class MostDigits {
   public static int findLongest(int[] numbers) {
	    int max = -1;
	    int indexOfHighestElement = 0;
	    for(int i =0;i<numbers.length;i++){
	      int nDigitsCurrentElement = countNumber(numbers[i]);
	      if(nDigitsCurrentElement > max){
	        max = nDigitsCurrentElement;
	        indexOfHighestElement = i;
	      }
	    }
	    return numbers[indexOfHighestElement];
	  }
	  
	  public static int countNumber(int n){
		  if(n<0) {
			  n = Math.abs(n);
		  }
	    int copia = n;
		  int contador = 0;
		  while(copia > 0){
			  int digito = copia%10;
			  contador++;
		    copia = copia/10;
		  }
	    return contador;
	  }
  
}