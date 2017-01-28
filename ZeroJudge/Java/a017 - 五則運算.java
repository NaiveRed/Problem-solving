import java.util.Scanner;
import java.util.Stack;

public class Main {

    public static void main(String[] args) {

        Scanner cin = new Scanner(System.in);
        while (cin.hasNext()) {
            String str = cin.nextLine();
            String postfix = getPost(str.toCharArray());
            System.out.println(calc(postfix));
        }

    }

    private static String getPost(char[] in) {

        int len = in.length;
        StringBuilder post = new StringBuilder();
        Stack<Character> s = new Stack<Character>();

        boolean isNum = false;
        for (int i = 0; i < len; i++) {
            if (Character.isDigit(in[i])) {
                {
                    isNum = true;
                    post.append(in[i]);
                }
            }
            else if (in[i] != ' ') {
                if (isNum) {
                    isNum = false;
                    post.append(' ');
                }

                if (in[i] == '(')
                    s.push('(');
                else if (in[i] == ')') {
                    while (s.peek() != '(') {
                        post.append(s.peek());
                        s.pop();
                    }
                    s.pop();
                }
                else {
                    while (!s.empty() && s.peek() != '(' && priority(in[i]) <= priority(s.peek())) {
                        post.append(s.peek());
                        s.pop();
                    }
                    s.push(in[i]);
                }
            }
        }

        if (isNum)
            post.append(' ');

        while (!s.empty()) {
            post.append(s.peek());
            s.pop();
        }

        return post.toString();
    }

    private static int priority(char c) {
        if (c == '+' || c == '-')
            return 1;
        else // if(c=='*'||c=='/'||c=='%')
            return 2;
    }

    private static int calc(String post) {

        Stack<Integer> s = new Stack<Integer>();
        int num = 0, len = post.length();
        char[] str = post.toCharArray();

        for (int i = 0; i < len; i++) {

            if (Character.isDigit(str[i])) {
                num = 0;
                while (Character.isDigit(str[i])) {
                    num = num * 10 + str[i] - '0';
                    i++;
                }
                s.push(Integer.valueOf(num));
            }
            else {
                int a, b;
                b = s.peek().intValue();
                s.pop();
                a = s.peek().intValue();
                s.pop();
                if (str[i] == '+')
                    a += b;
                else if (str[i] == '-')
                    a -= b;
                else if (str[i] == '*')
                    a *= b;
                else if (str[i] == '/')
                    a /= b;
                else if (str[i] == '%')
                    a %= b;
                s.push(Integer.valueOf(a));
            }

        }

        return s.peek().intValue();
    }
}
