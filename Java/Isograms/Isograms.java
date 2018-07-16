public class isogram {
    public static boolean  isIsogram(String str) {
    //65 To 90 is A to Z
	//97 To 122 is a to z
		boolean alphabetInAscii[] = new boolean[26];
		falsify(alphabetInAscii);
		for(int i =0;i<str.length();i++){
			char current = str.charAt(i);
			current = Character.toLowerCase(current);
			int ascii = (int) current;
			//to get the value from 0 to 25
			ascii -= 97;
			
			if(alphabetInAscii[ascii] == false) {
				alphabetInAscii[ascii] = true;
			}
			else {
				return false;
			}
		}
		return true;
    } 
    
    public static void falsify(boolean arr[]){
     for(int i =0;i<arr.length;i++) {
			arr[i] = false;
		}
    }
}