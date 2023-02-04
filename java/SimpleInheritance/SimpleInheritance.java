package SimpleInheritance;

class SimpleInheritance {

    public static void main(String[] args) {
        A superOb = new A();
        B subOb = new B();

        superOb.i = 10;
        superOb.j = 20;

        System.out.println("Contents of SuperOb: ");
        superOb.showij();
        System.out.println();

        subOb.i = 7;
        subOb.j = 8;
        subOb.k = 9;

        System.out.println("Contents of SubOb: ");
        subOb.showij();
        subOb.showk();
        System.out.println();
    
        System.out.println("\nSum of i, j, and k in SubOb: ");
        subOb.sum();
    }

}

// create class solid
// inherit cone and sphere
