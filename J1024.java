import java.math.BigInteger;
import java.util.*;

public class J1024 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger result = new BigInteger(sc.next());
        int k = sc.nextInt();
        sc.close();
        int i;
        for(i = 0; i < k; i++) {
            String s = result.toString();
            StringBuffer left = new StringBuffer(s.substring(0, s.length() / 2));
            StringBuffer right = new StringBuffer(s.substring(s.length() / 2 + s.length() % 2, s.length())).reverse();
            if(left.toString().equals(right.toString())) {
                break;
            }
            StringBuffer re = new StringBuffer(result.toString()).reverse();
            result = result.add(new BigInteger(re.toString()));
            // System.out.println(result);
        }
        System.out.println(result);
        System.out.println(i);
    }
}