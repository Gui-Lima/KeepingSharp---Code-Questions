/*
  How we do that is we keep dividing the number by five and 
  adding the (int) rest to a total. The math behind this is that 
  we are getting the factors of 10 of a number(this gives the numbers of 0)
  We get this factors by how much 2*5 there are. Since there are a lot of "2"
  (half of the numbers) we only need to get the "5".

*/
public class Solution {
     public static int zeros(int n) {
        double divisionRest = ( double ) n;
        int resultWithoutFloat = 0;

        while(divisionRest > 1) {
            divisionRest = divisionRest / 5;
            resultWithoutFloat += (int) divisionRest;
        }
        return resultWithoutFloat;
    }
}