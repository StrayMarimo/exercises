package Pricelist;
import java.util.*;
import java.io.*;

public class GroceryClass {
    private String[] codes;
    private String code;
    private double[] prices;
    private int qty;
    private double price;
    int count = 0;
    
    public GroceryClass(String file) throws IOException {
        try{
            Scanner input = new Scanner(new File(file));
            codes = new String[1000];
            prices = new double[1000];
            
            while(input.hasNextLine()){
                codes[count] = input.next();
                prices[count] = input.nextDouble();
                count++;
            }
        }catch (FileNotFoundException e){
            System.out.println("File not found");
            System.exit(0);
        }
    }
    public void setCodeQty(String code, int qty){
        this.code = code;
        this.qty = qty;
    }
    
    public String getCode(){
        return code;
    }
    
    public int getQty(){
        return qty;
    }
    
    public boolean setPrice(){
        for(int i = 0; i < count; i++){
            if(codes[i].equals(code)){
                price = prices[i];
                return true;
            }
        }
        System.out.println("PRODUCT NOT FOUND.");
        price = 0.0;
        return false;
    }
    
    public double getPrice(){
        return price;
    }
    
    public double getSubTotal(){
        return price * qty;
    }

}
