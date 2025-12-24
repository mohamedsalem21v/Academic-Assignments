import java.util.Scanner;

public class assignment1 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = input.nextInt();
        for (int i = 2; i <= n; i++) {
            System.out.println(i);
        }
        input.close();
    }
}
