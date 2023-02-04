package Shipment;

class ShipmentClass extends BoxWeight{
    double cost;

    ShipmentClass(ShipmentClass ob) {
        super(ob);
        cost = ob.cost;
    }

    ShipmentClass(double w, double h, double d, double m, double c) {
        super (w, h, d, m);
        cost = c;
    }

    ShipmentClass() {
        super();
        cost = -1;
    }

    ShipmentClass(double len, double c) {
        super(len, c);
        cost = c;
    }
}
