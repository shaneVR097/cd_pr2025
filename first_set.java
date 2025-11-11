import java.util.*;

public class FirstSet {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter production (example: E->aA|b): ");
        String prod = sc.next();

        char nt = prod.charAt(0);
        System.out.print("FIRST(" + nt + ") = { ");

        for (int i = 3; i < prod.length(); i++) {
            char ch = prod.charAt(i);
            if (ch >= 'a' && ch <= 'z') {
                System.out.print(ch + " ");
                break;
            } else if (ch == '|') continue;
        }
        System.out.println("}");
    }
}

/*
Example Inputs & Outputs:
1️⃣ E->aA|b  →  FIRST(E) = { a }
2️⃣ S->bB|a  →  FIRST(S) = { b }
3️⃣ A->ε|dA  →  FIRST(A) = { ε }
*/
