public class Dinglemouse {
    public static int[] findWrongWayCow(final char[][] field) {
        // Your cow finding code here
        int north = 0;
        int[] northPos = new int[2];
        int east = 0;
        int[] eastPos = new int[2];
        int west = 0;
        int[] westPos = new int[2];
        int south = 0;
        int[] southPos = new int[2];
        for(int i = 0;i<field.length;i++){
            for(int j = 0; j < field[i].length;j++){
                //search for 'c's
                if( field[i][j] == 'c'){
                    System.out.println("found a cow!");
                    //what direction is it facing?
                    if(j > 1 && field[i][j-1] == 'o' && field[i][j-2] == 'w'){
                        System.out.println("facing west");
                        west++;
                        westPos[0] = j;
                        westPos[1] = i;
                    }
                    else if(j < field[i].length - 2 &&  field[i][j+1] == 'o' && field[i][j+2] == 'w'){
                        System.out.println("facing east");
                        east++;
                        eastPos[0] = j;
                        eastPos[1] = i;
                    }
                    else if(i < field.length - 2 && field[i+1][j] == 'o' && field[i+2][j] == 'w'){
                        System.out.println("facing south");
                        south++;
                        southPos[0] = j;
                        southPos[1] = i;
                    }
                    else if(i > 1 && field[i-1][j] == 'o' && field[i-2][j] == 'w'){
                        System.out.println("facing north");
                        north++;
                        northPos[0] = j;
                        northPos[1] = i;
                    }
                }
            }
        }

        if(north == 1){
            return northPos;
        }
        if(south == 1){
            return southPos;
        }
        if(east == 1){
            return eastPos;
        }
        if(west == 1){
            return westPos;
        }
        return new int[]{0,0};
    }

}