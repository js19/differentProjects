import java.math.BigInteger;
import java.util.*;

public class main {

    //given a string, URLify the string by changing spaces
    //to %20, the challenge requested to use an array if using Java.
    //EX: "Hello World   " -> Hello%20World
    //The spaces are added to end to account for extra characters.

    public static void main(String args[]){

        String s = getInput();
        modifiyStringHardWay(s);
        modifiyStringEasyWay(s);


    }

    public static String getInput(){
        Scanner scanner = new Scanner(System.in);
        scanner.nextLine();
        return scanner.nextLine();
    }

    public static void modifiyStringHardWay(String s){
        char characterArray[];
        characterArray = new char[s.length()];
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == ' '){
                if(s.charAt(i+1) == ' '){
                    break;
                }
                characterArray[j] = '%';
                characterArray[j + 1] = '2';
                characterArray[j + 2] = '0';
                j = j + 3;
            }else{
                characterArray[j] = s.charAt(i);
                j++;
            }

        }
        System.out.println(characterArray);
    }

    public static void modifiyStringEasyWay(String s){
        String pattern = "(\\s)";
        String endPattern = "(\\s)+$";
        s = s.replaceAll(endPattern, "");
        System.out.println(s.replaceAll(pattern, "%20"));
    }
}
