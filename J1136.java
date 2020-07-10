import java.math.BigInteger;
import java.util.*;

public class J1136 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger result = new BigInteger(sc.next());
        sc.close();
        int i;
        for(i = 0; i < 10; i++) {
            String s = result.toString();
            StringBuffer left = new StringBuffer(s.substring(0, s.length() / 2));
            StringBuffer right = new StringBuffer(s.substring(s.length() / 2 + s.length() % 2, s.length())).reverse();
            if(left.toString().equals(right.toString())) break;
            StringBuffer re = new StringBuffer(result.toString()).reverse();
            System.out.print(result + " + " + re);
            result = result.add(new BigInteger(re.toString()));
            System.out.println(" = " + result);
        }
        if (i == 10) System.out.println("Not found in 10 iterations.");
        else System.out.println(result + " is a palindromic number.");
    }

}