import java.util.*;

public class Main {

    private static Scanner in = new Scanner(System.in);
    private static BitSet bs = new BitSet(1_000_001);

    public static void main(String[] args) {

        sieve();

        int n = in.nextInt();

        while(n != 0) {

            int ans = digitalRoot(n);

            if (ans != -1)
                System.out.printf("%7d %7d\n", n, ans);
            else
                System.out.printf("%7d %7s\n", n, "none");

            n = in.nextInt();
        }
    }

    public static int digitalRoot(int n){

        int sum = 0;

        if(isPrime(n)) return n;

        while (n > 9){

            sum = 0;

            //Sum the digit of the number
            while(n != 0){
                sum += n % 10;
                n /= 10;
            }

            n = sum;

            if (isPrime(n)) return n;
        }

        return -1;
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
