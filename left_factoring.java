import java.util.*;

public class LeftFactoring {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter production (example: E->aA|aB): ");
        String prod = sc.next();

        int pos = prod.indexOf('|');
        if (pos == -1) {
            System.out.println("No Left Factoring.");
            return;
        }

        String part1 = prod.substring(3, pos);
        String part2 = prod.substring(pos + 1);
        int j = 0;

        while (j < part1.length() && j < part2.length() && part1.charAt(j) == part2.charAt(j))
            j++;

        if (j == 0) {
            System.out.println("No Left Factoring.");
        } else {
            char nt = prod.charAt(0);
            System.out.println("Left Factored Grammar:");
            System.out.println(nt + "->" + part1.substring(0, j) + nt + "'");
            System.out.println(nt + "'->" + part1.substring(j) + "|" + part2.substring(j));
        }
    }
}

/*
Example Inputs & Outputs:
1️⃣ E->aA|aB  →  
Left Factored Grammar:
E->aE'
E'->A|B

2️⃣ S->ab|ac  →  
S->aS'
S'->b|c

3️⃣ A->xy|pq  →  
No Left Factoring.
*/
