/*
  input 2 digits
  generate random number 0 to 99
  if exact match, win 10,000
  if different arrangement, win 3,000
  if one match, win 1,000
  otherwise lose
*/
import java.util.Scanner;
import java.math.*;
public class Lottery {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int guess = -1;
		int lottery = (int) (Math.random() * 100);
		System.out.println(lottery);
		do {
			System.out.print("Guess a number from 0 to 99: ");
			guess = sc.nextInt();
		} while (guess < 0 || guess >= 100);
		
		if (guess == lottery)
			System.out.println("Exact Match! You won 10,000");
		else if (guess / 10 == lottery % 10 && guess % 10  == lottery / 10)
			System.out.println("2 digits match. You won 3,000!");
		else if (guess / 10 == lottery / 10 ||
			 guess / 10 == lottery % 10 ||
			 guess % 10 == lottery / 10 ||
			 guess % 10 == lottery % 10 )
			System.out.println("One match. You won 1,000!");
		else
			System.out.println("Sorry, no matches."); 		
	}
}