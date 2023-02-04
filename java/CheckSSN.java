//   Correct format DDD-DD-DDDD

import java.util.Scanner;

public class CheckSSN {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String SSN = sc.nextLine();
		int pos = 0;
		boolean isValid = true;
		if (SSN.length() == 11) {
			for (char x: SSN.toCharArray()) {
				if (pos == 3 || pos == 6) {
					if (x != '-') {
						isValid = false;
						break;
					}		
				} else {
					if (!Character.isDigit(x)) {
						isValid = false;
						break;
					}	
				}
				pos++;
			}
		} else {
			isValid = false;
		}
		
		if (isValid)
			System.out.printf("%s is a valid SSN.%n", SSN);
		else
			System.out.printf("%s is an invalid SSN.%n", SSN);		
		
	}
	
}