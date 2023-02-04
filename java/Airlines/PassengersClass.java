package Airlines;

public class PassengersClass {
    //data fields
    public int passengerID;
    public int flightID;
    private String name;
    private String nationality;
    private String flightType;
    private String flightClass;
    private boolean isPriority;
    
    //constructor
    PassengersClass(int passengerID, int flightId){
        this.passengerID = passengerID;
        this.flightID = flightId;
    }

    // mutators
    public void setName(String name) {
        this.name = name;
    }

    public void setNationality(String nationality) {
        this.nationality = nationality;
    }

    public void setFlightType(String flightType) {
        this.flightType = flightType;
    }

    public void setFlightClass(String flightClass) {
        this.flightClass = flightClass;
    }

    public void setIsPriority(boolean isPriority) {
        this.isPriority = isPriority;
    }

    // accessors
    public String getName() {
        return name;
    }

    public String getNationality() {
        return nationality;
    }

    public String getFlightType() {
        return flightType;
    }

    public String getFlightClass() {
        return flightClass;
    }

    public boolean getIsPriority() {
        return isPriority;
    }
    
}
