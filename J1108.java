import java.util.Scanner;

public class J1108 {
    public static void main(String[] args) {
        int n, count = 0;
        double result = 0;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(int i = 0; i < n; i++) {
            String s = sc.next();
            if(check(s)) {
                result += Double.parseDouble(s);
                count++;
            }
            else {
                System.out.println("ERROR: " + s + " is not a legal number");
            }
        }
        if(count > 1)
            System.out.printf("The average of %d numbers is %.2f", count, result / count);
        else if (count == 1) {
            System.out.printf("The average of 1 number is %.2f", result);
        }
        else {
            System.out.printf("The average of 0 numbers is Undefined");
        }
        sc.close();
    }

    public static Boolean check(String s) {
        double b = 10;
        try {
            b = Double.parseDouble(s);
        }
        catch (Exception e) { return false; }
        if(b > 1000 || b < -1000) return false;
        if(s.split("\\.").length == 2 && s.split("\\.")[1].length() > 2) return false;
        return true;
    }
}