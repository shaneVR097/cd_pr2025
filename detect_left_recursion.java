import java.util.*;

public class LeftRecursion {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter production (like A->Aa|b): ");
        String prod = sc.next();

        char lhs = prod.charAt(0);
        int arrowPos = prod.indexOf("->");
        if (arrowPos == -1) {
            System.out.println("Invalid production format.");
            return;
        }

        String rhs = prod.substring(arrowPos + 2);
        String[] alts = rhs.split("\\|");
        boolean leftRec = false;

        for (String alt : alts) {
            alt = alt.trim();
            if (!alt.isEmpty() && alt.charAt(0) == lhs) {
                leftRec = true;
                break;
            }
        }

        if (leftRec)
            System.out.println("Immediate left recursion detected for " + lhs + ".");
        else
            System.out.println("No immediate left recursion detected for " + lhs + ".");
    }
}

/*
Example Inputs & Outputs:

1️⃣ Input: A->Aa|b  
    Output: Immediate left recursion detected for A.

2️⃣ Input: E->E+T|T  
    Output: Immediate left recursion detected for E.

3️⃣ Input: S->aS|b  
    Output: No immediate left recursion detected for S.
*/
