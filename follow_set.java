import java.util.*;

public class FollowSet {
    static String[] prod = new String[10];
    static int n;
    static StringBuilder followRes = new StringBuilder();

    static void addToResult(char ch) {
        if (followRes.indexOf(String.valueOf(ch)) == -1)
            followRes.append(ch);
    }

    static void first(char c) {
        if (!Character.isUpperCase(c)) {
            addToResult(c);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (prod[i].charAt(0) == c) {
                if (prod[i].length() <= 3) continue;
                char next = prod[i].charAt(3);
                if (!Character.isUpperCase(next))
                    addToResult(next);
                else
                    first(next);
            }
        }
    }

    static void follow(char c) {
        if (prod[0].charAt(0) == c)
            addToResult('$');

        for (int i = 0; i < n; i++) {
            String rhs = prod[i].substring(3);
            for (int j = 0; j < rhs.length(); j++) {
                if (rhs.charAt(j) == c) {
                    if (j + 1 < rhs.length())
                        first(rhs.charAt(j + 1));
                    else if (c != prod[i].charAt(0))
                        follow(prod[i].charAt(0));
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of productions: ");
        n = sc.nextInt();
        System.out.println("Enter productions (like E->E+T):");
        for (int i = 0; i < n; i++)
            prod[i] = sc.next();

        System.out.println("\nFOLLOW Sets:");
        for (int i = 0; i < n; i++) {
            char nonterm = prod[i].charAt(0);
            followRes.setLength(0);
            follow(nonterm);
            System.out.print("FOLLOW(" + nonterm + ") = { ");
            for (int j = 0; j < followRes.length(); j++)
                System.out.print(followRes.charAt(j) + " ");
            System.out.println("}");
        }
    }
}

/*
Example Input:
Enter number of productions: 3
Enter productions (like E->E+T):
E->E+T
E->T
T->T*F
T->F
F->(E)
F->id

Expected Output:
FOLLOW(E) = { $ ) }
FOLLOW(T) = { + $ ) }
FOLLOW(F) = { * + $ ) }
*/
