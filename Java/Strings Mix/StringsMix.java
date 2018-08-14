import java.util.ArrayList;
public class Mixing{
   
    public static String mix(String s1, String s2){
        //"2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss"

        int s1Hash[] = makeAsciiHashes(s1);
        int s2Hash[] = makeAsciiHashes(s2);

        ArrayList al = new ArrayList();
        String result = "";

        for(int i =0;i<s1Hash.length && i<s2Hash.length;i++){
            if(s1Hash[i] >= 2 && s1Hash[i] > s2Hash[i]){
                String temp = "1:";
                for(int j = 0;j<s1Hash[i];j++){
                    Character eachChar = (char) (i+97);
                    temp = temp.concat(eachChar.toString());
                }
                temp =temp.concat("/");
                al.add(temp);
            }
            if(s2Hash[i] >= 2 && s2Hash[i] > s1Hash[i]){
                String temp = "2:";
                for(int j = 0;j<s2Hash[i];j++){
                    Character eachChar = (char) (i+97);
                    temp = temp.concat(eachChar.toString());
                }
                temp = temp.concat("/");
                 al.add(temp);
            }
              if(s1Hash[i] >= 2 && s2Hash[i] >=2 &&  s2Hash[i] == s1Hash[i]){
                String temp = "=:";
                for(int j = 0;j<s1Hash[i];j++){
                    Character eachChar = (char) (i+97);
                    temp = temp.concat(eachChar.toString());
                }
                temp = temp.concat("/");
                 al.add(temp);
            }
        }
        String cu[] = new String[al.size()];
        cu = (String[]) al.toArray(cu);
        cu = sort(cu);

        for(int i =0;i<cu.length;i++){
            result = result.concat(cu[i]);
        }

        String realResult = "";
        for(int i =0;i<result.length();i++){
            realResult = (String) realResult.concat(String.valueOf(result.charAt(i)));
        }

        return realResult;
    }

    public static String[] sort(String[] arr){
        for ( int i =0;i<arr.length;i++){
            for ( int  j = 0;j<arr.length ; j++){
                if(arr[i].length() > arr[j].length()){
                    String temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        return arr;
    }

    public static int[] makeAsciiHashes(String s1){
        int Hash[] = new int[26];
        for(int i =0;i<Hash.length;i++){
            Hash[i] = 0;
        }

        for(int i = 0;i<s1.length();i++){
            if(Character.isLowerCase(s1.charAt(i)))
                Hash[s1.charAt(i) - 97]++;
        }

        return Hash;
    }
}
