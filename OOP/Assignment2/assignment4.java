import java.util.Scanner;

public class assignment4 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter a string: ");
        String str = input.nextLine(); // read full line (keeps spaces)
        String reversed = "";

        // Loop backwards to reverse the string
        for (int i = str.length() - 1; i >= 0; i--) {
            reversed += str.charAt(i);
        }

        System.out.println("Reversed string: " + reversed);
        input.close();
    }
}
