//a003
import java.util.Scanner;

public class Java_Solve
{

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);

        while (cin.hasNext())
        {
            int M = cin.nextInt(), D = cin.nextInt();
            switch ((M * 2 + D) % 3)
            {
                case 0:
                    System.out.println("普通");
                    break;
                case 1:
                    System.out.println("吉");
                    break;
                case 2:
                    System.out.println("大吉");
                    break;
            }
        }
    }
}
