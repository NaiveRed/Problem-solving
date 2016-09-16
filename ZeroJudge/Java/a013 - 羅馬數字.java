
import java.util.Scanner;

public class Java_Solve
{

    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);

        String n1, n2, n3;
        while (!(n1 = cin.next()).equals("#"))
        {
            n2 = cin.next();
            n3 = new String();
            int ans = Math.abs(toNum(n1) - toNum(n2));

            if (ans == 0)
                System.out.println("ZERO");
            else
            {
                while (ans > 0)
                {
                    if (ans >= 1000)
                    {
                        ans -= 1000;
                        n3 += "M";
                    }
                    else if (ans >= 900)
                    {
                        ans -= 900;
                        n3 += "CM";
                    }
                    else if (ans >= 500)
                    {
                        ans -= 500;
                        n3 += "D";
                    }
                    else if (ans >= 400)
                    {
                        ans -= 400;
                        n3 += "CD";
                    }
                    else if (ans >= 100)
                    {
                        ans -= 100;
                        n3 += "C";
                    }
                    else if (ans >= 90)
                    {
                        ans -= 90;
                        n3 += "XC";
                    }
                    else if (ans >= 50)
                    {
                        ans -= 50;
                        n3 += "L";
                    }
                    else if (ans >= 40)
                    {
                        ans -= 40;
                        n3 += "XL";
                    }
                    else if (ans >= 10)
                    {
                        ans -= 10;
                        n3 += "X";
                    }
                    else if (ans >= 9)
                    {
                        ans -= 9;
                        n3 += "IX";
                    }
                    else if (ans >= 5)
                    {
                        ans -= 5;
                        n3 += "V";
                    }
                    else if (ans >= 4)
                    {
                        ans -= 4;
                        n3 += "IV";
                    }
                    else
                    {
                        ans -= 1;
                        n3 += "I";
                    }
                }

                System.out.println(n3);
            }
        }
    }

    public static int toNum(String n)
    {
        int len = n.length(), num = 0;
        for (int i = 0; i < len; i++)
        {
            char c = n.charAt(i);
            if (c == 'I')
            {
                num++;
            }
            else if (c == 'V')
            {
                num += 5;
                if (i != 0 && n.charAt(i - 1) == 'I')
                {
                    num -= 2;
                }
            }
            else if (c == 'X')
            {
                num += 10;
                if (i != 0 && n.charAt(i - 1) == 'I')
                {
                    num -= 2;
                }
            }
            else if (c == 'L')
            {
                num += 50;
                if (i != 0 && n.charAt(i - 1) == 'X')
                {
                    num -= 20;
                }
            }
            else if (c == 'C')
            {
                num += 100;
                if (i != 0 && n.charAt(i - 1) == 'X')
                {
                    num -= 20;
                }
            }
            else if (c == 'D')
            {
                num += 500;
                if (i != 0 && n.charAt(i - 1) == 'C')
                {
                    num -= 200;
                }
            }
            else if (c == 'M')
            {
                num += 1000;
                if (i != 0 && n.charAt(i - 1) == 'C')
                {
                    num -= 200;
                }
            }
        }

        return num;
    }
}
