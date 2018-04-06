import java.util.*;

public class Main {

    private static int N = 1_000_005;
    private static Scanner in = new Scanner(System.in);
    private static BitSet bs = new BitSet(N);

    public static void main(String[] args) {

        sieve();

        while(in.hasNextInt()) {

            int a = in.nextInt();
            int b = reverse(a);

            if (isPrime(a) && isPrime(b))
                System.out.println(a + " is emirp.");
            else if (isPrime(a))
                System.out.println(a + " is prime.");
            else
                System.out.println(a + " is not prime.");
        }
    }

    public static int reverse(int n){

        String num = Integer.toString(n);
        String res = "";

        for (int i = num.length() - 1; i >= 0; i--)
            res += num.charAt(i);

        return Integer.parseInt(res);
    }

    public static boolean isPrime(int n){

        return bs.get(n) == false;
    }

    public static void sieve(){

        bs.set(0, true); bs.set(1, true);

        for (int i = 2; i * i < N; i++) {
            if (bs.get(i) == false) {

                for (int j = i * i; j < N; j += i)
                    bs.set(j, true);
            }
        }
    }
}
