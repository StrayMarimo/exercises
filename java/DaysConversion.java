import java.util.Scanner;
public class DaysConversion {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int minutes = sc.nextInt();
		int minutesInYear = 60 * 24 * 365;
		int days = (int) (minutes/60/24) % 365;
		System.out.println(minutes + " minutes is approximately " + (minutes/minutesInYear) + " years and  " + days + " days");
	}
}