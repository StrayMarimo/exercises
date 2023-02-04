package Pricelist;
import java.util.*;
import java.io.*;

public class Grocery {
    public static void main(String[] args) throws IOException {
	    Scanner input = new Scanner(System.in);
		GroceryClass store = new GroceryClass("pricelist/pricelist.txt");
		int qty;
		String code;
		double price, total = 0.0;
		
		System.out.println("Enter 0 0 to quit and compute total.");
	    System.out.print("Enter Product Code and Quantity: ");
	    
        code = input.next();
        qty = input.nextInt();
        
        while(!code.equals("0") && qty != 0){
            store.setCodeQty(code, qty);
                if(store.setPrice()) {
                    price = store.getPrice();
                    System.out.println(qty + " @ Php "+ price + " Php "+ store.getSubTotal());
                    total += store.getSubTotal();
                }
            System.out.print("Enter Product Code and Quantity: ");
            code = input.next();
            qty = input.nextInt();
        }
        System.out.println("TOTAL PRICE: " + total);
        System.exit(0);
	}
}
