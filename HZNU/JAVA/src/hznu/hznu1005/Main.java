package hznu.hznu1005;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n, m, a;
        int count = 1;
        int k = 0;
        while (true) {
            n = scanner.nextInt();
            m = scanner.nextInt();
            if (n == 0 || m == 0) {
                break;
            }
            if (k > 0) {
                System.out.println();
            }
            int maxVal = -9999;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a = scanner.nextInt();
                    maxVal = a > maxVal ? a : maxVal;
                }
            }
            System.out.printf("Case %d:\n", count++);
            System.out.println(maxVal);
            k++;
        }
    }
}
