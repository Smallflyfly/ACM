package hznu.hznu1004;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int T;
        Scanner scanner = new Scanner(System.in);
        T = scanner.nextInt();
        scanner.nextLine();
        while (T > 0) {
            String s = scanner.nextLine();
            System.out.println(new StringBuffer(s).reverse().toString());
            if (T > 1) {
                System.out.println();
            }
            T --;
        }
    }
}
