/*
 * shipment 1 = 10 20 15 10 3.41
 * shipment 2 = 2 3 4 0.76 1.28 
 */

package Shipment;

class Shipment {
    public static void main(String[] args) {
        ShipmentClass shipment1 = new ShipmentClass(10, 20, 15, 10, 3.41);
        ShipmentClass shipment2 = new ShipmentClass(2, 3, 4, 0.76, 1.28);

        System.out.println(shipment1.volume());
        System.out.println(shipment1.weight);
        System.out.println(shipment1.cost);
        System.out.println();
        System.out.println(shipment2.volume());
        System.out.println(shipment2.weight);
        System.out.println(shipment2.cost);
    }
}
