public class DoubleCola {

	public static void main(String[] args) {
		String[] names = new String[] { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
		System.out.println(WhoIsNext(names, 7));

	}
    public static String WhoIsNext(String[] names, int n){
         // First i have to know the closest m so that names.length * 2 ^ m = n
         // I'll have to loop at max 35 times to find that m
         // Then i'll divide m into names.lengthparts
         // Each part will be a range of names. So from m to m + m/names.length will be name1; from m + m/names.length to m + m/names.length + m/names.length will be name2
		 // etc

		if(n <= names.length){
			return names[n-1];
		}
		
		int multFactor = names.length;
		long reachMax = 0;
		long auxReach = 0;
		for(int i =0;i<50;i++){
			auxReach = reachMax;
			reachMax += multFactor * Math.round(Math.pow(2, i));
			System.out.println("Getting the higher number below " + n + " : " + reachMax);
			if(reachMax > n){
				System.out.println("The person is in the group: " + (i+1) + " meaning people from " + auxReach + " to " + reachMax);
				break;
			}
		}
		long repetitionPeople = reachMax - auxReach;
		System.out.println("This group has " + repetitionPeople + " people, meaning it will have " + repetitionPeople/multFactor + " of each person");
		long rangeMin = auxReach + 1;
		long rangeMax = rangeMin + (repetitionPeople/multFactor);
		for(int i =0;i<multFactor;i++){
			rangeMax = rangeMin + (repetitionPeople/multFactor);
			System.out.println("From " + (rangeMin) + " to " + (rangeMax) + "(exlusive) is " + names[i]);
			if(inBetween(n, rangeMin, rangeMax)){
				return names[i];
			}
			rangeMin += repetitionPeople/multFactor;
		}
		return "";
	}
	
	public static boolean inBetween(long n, long floor, long ceilling){
		if(n >= floor && n < ceilling){
			return true;
		}
		return false;
	}
 }