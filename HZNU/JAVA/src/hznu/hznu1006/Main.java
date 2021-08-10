package hznu.hznu1006;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        BigInteger x, a;
        int count = 1;
        while (scanner.hasNextInt()) {
            n = scanner.nextInt();
            x = scanner.nextBigInteger();
            System.out.printf("Case %d:\n", count++);
            int flag = 0;
            for (int i = 0; i< n; i++) {
                a = scanner.nextBigInteger();
                if (!x.equals(a)) {
                    if (flag == 0) {
                        System.out.print(a);
                    } else {
                        System.out.print(" " + a);
                    }
                    flag ++;
                }
            }
            if (flag == 0) {
                System.out.println("Empty!");
            }
            System.out.println();
        }
    }
}
