import java.util.Scanner;
 
public class MultiplyDigits {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int number = sc.nextInt();
		int product = 1;
		while (number > 0) {
			product *= (number % 10); 
			number/= 10;
		}
		System.out.println(product);		
		
	}
}