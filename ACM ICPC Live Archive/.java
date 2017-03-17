import java.io.*;
import java.util.*;

public class Main {

    private static Scanner in = new Scanner(System.in);
    private static BitSet bs = new BitSet(1_000_001);

    public static void main(String[] args) {

        sieve();

        int n = in.nextInt();
        int c = 0;

        while (n != 0) {

            int tmp = n;

            System.out.print(c++ > 0 ? '\n' : '\0');

            while (Integer.toString(n).length() != 1) {

                if (!isPrime(n)) {
                    n = digitSum(n);
                } else {
                    break;
                }
            }

            int ans = isPrime(n) ? n : tmp;
            System.out.printf("%7d%7s", tmp, isPrime(n) ? Integer.toString(n) : "none");

            n = in.nextInt();
        }
    }

    public static int digitSum(int n){

        String a = Integer.toString(n);
        int sum = 0;

        for (int i = 0; i < a.length(); i++)
            sum += a.charAt(i) - '0';

        return sum;
    }

    public static boolean isPrime(int n){

        return bs.get(n) == false;
    }

    public static void sieve(){

        int N = 1_000_001;

        bs.set(0, true); bs.set(1, true);

        for (int i = 2; i * i < N; i++) {
            if (bs.get(i) == false) {

                for (int j = i * i; j < N; j += i)
                    bs.set(j, true);
            }
        }
    }
}
