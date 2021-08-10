package hznu.hznu1003;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int T;
        Scanner scanner = new Scanner(System.in);
        T = scanner.nextInt();
        int i = 1;
        while (T > 0) {
            BigInteger a = scanner.nextBigInteger();
            BigInteger b = scanner.nextBigInteger();
            System.out.printf("Case %d:\n", i++);
            System.out.println(a.add(b));
            if (T > 1) {
                System.out.println();
            }
            T --;
        }
    }
}
