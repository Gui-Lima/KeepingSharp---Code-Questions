public class Greed{
    public static int greedy(int[] dice){
      int[] hashdice = new int[7];
      for(int i =0;i<hashdice.length;i++){
        hashdice[i] = 0;
      }
      for(int i =0;i<dice.length;i++){
        hashdice[dice[i]]++;
      }

      if(hashdice[1] >=3){
        return 1000 + (hashdice[1] - 3) * 100 + hashdice[5] * 50;
      }
      if(hashdice[2] >= 3){
        return 200 + hashdice[1] * 100 + hashdice[5] * 50;
      }
      if(hashdice[3] >= 3){
        return 300 + hashdice[1] * 100 + hashdice[5] * 50;
      }
      if(hashdice[4] >= 3){
        return 400 + hashdice[1] * 100 + hashdice[5] * 50;
      }
      if(hashdice[5] >= 3){
        return 500 + hashdice[1] * 100 + (hashdice[5] - 3) * 50;
      }
      if(hashdice[6] >= 3){
        return 600 + hashdice[1] * 100 + hashdice[5] * 50;
      }
      else{
        return hashdice[1] * 100 + hashdice[5] * 50;
      }
      return 0;
    }
  }


  /*
 Three 1's => 1000 points
 Three 6's =>  600 points
 Three 5's =>  500 points
 Three 4's =>  400 points
 Three 3's =>  300 points
 Three 2's =>  200 points
 One   1   =>  100 points
 One   5   =>   50 point

  */