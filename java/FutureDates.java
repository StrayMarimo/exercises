import java.util.Scanner;

public class FutureDates {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		System.out.print("Enter today's day: ");
		int today = sc.nextInt();
		System.out.print("Enter the number of days elapsed since today: ");
		int elapsed = sc.nextInt();
		System.out.printf("Today is %s and the future day is %s.%n", days[today], days[(today + elapsed) % 7] );			
	}
}