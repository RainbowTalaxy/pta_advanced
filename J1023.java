import java.math.BigInteger;
import java.util.Scanner;

public class J1023 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();
        sc.close();
        int[] k = new int[10];
        int[] s = new int[10];
        for(int i = 0; i < 10; i++) {
            k[i] = 0;
            s[i] = 0;
        }
        for(int i = 0; i < n.length(); i++) {
            int m = Integer.parseInt(String.valueOf(n.charAt(i)));
            k[m]++;
        }
        BigInteger number = new BigInteger(n);
        BigInteger a = new BigInteger("2");
        // System.out.println(number);
        number = number.multiply(a);
        // System.out.println(number);
        String n2 = number.toString();
        for(int i = 0; i < n.length(); i++) {
            int m = Integer.parseInt(String.valueOf(n2.charAt(i)));
            s[m]++;
        }
        for(int i = 0; i < 10; i++) {
            if(k[i] != s[i]) {
                System.out.println("No");
                System.out.println(n2);
                return;
            }
        }
        System.out.println("Yes");
        System.out.println(n2);
    }
}