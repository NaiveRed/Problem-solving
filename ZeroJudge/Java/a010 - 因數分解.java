
import java.util.Scanner;

public class Java_Solve{

    public static void main(String[] args)
    {
        int[] prime = new int[1000];
        boolean[] sieve = new boolean[1000];
        sieve[0] = sieve[1] = true;
        int p = 0;

        for (int i = 2; i < 31; i++)
        {
            if (!sieve[i])
            {
                for (int j = i + i; j < 1000; j += i)
                    sieve[j] = true;
            }
        }

        for (int i = 2; i < 1000; i++)
            if (!sieve[i])
                prime[p++] = i;

        Scanner cin = new Scanner(System.in);
        int n, i;
        boolean first;
        while (cin.hasNext())
        {
            first = true;
            i = 0;
            n = cin.nextInt();
            while (n != 1 && i < p)
            {
                int count = 0;
                if (n % prime[i] == 0)
                {
                    while (n % prime[i] == 0)
                    {
                        count++;
                        n /= prime[i];
                    }
                }

                if (count > 0)
                {
                    if (first)
                        first = false;
                    else
                        System.out.print(" * ");

                    System.out.print(prime[i]);
                    if (count > 1)
                        System.out.printf("^%d", count);
                }

                i++;
            }

            if (n > 1)
                System.out.printf(" * %d\n", n);
            else
                System.out.print('\n');
        }
    }
}
