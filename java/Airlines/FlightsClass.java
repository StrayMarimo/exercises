package Airlines;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.Duration;

public class FlightsClass {
    // data fields
    public int flightID;
    public int airlineID;
    private boolean isDomestic;
    private String departureLocation;
    private LocalDateTime departureSchedule;
    private Duration flighDuration;
    public static int[][] passengers = new int[60][12];
    public static int passengerSize[] = new int[12];

    // constructor
    FlightsClass(int flightId, int airlineID){
        this.flightID = flightId;
        this.airlineID = airlineID;
    }

    // mutators

    public void setIsDomestic(boolean isDomestic) {
        this.isDomestic = isDomestic;
    }

    public void setDepartureLocation(String departureLocation) {
        this.departureLocation = departureLocation;
    }

    public void setDepartureSchedule(String departureSchedule) {
        // converts string to localDateTime format
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");
        this.departureSchedule = LocalDateTime.parse(departureSchedule, formatter);
    }

    public void setFlighDuration(String flighDuration) {
        // converts string to Duration data type and stores to data field
        this.flighDuration = Duration.parse(flighDuration);
    }

    // accessors
    
    public boolean getIsDomestic() {
        return isDomestic;
    }

    public String getDepartureLocation() {
        return departureLocation;
    }
    
    public String getDepartureSchedule() {
        // converts localDateTime data type to string to be returned
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");
        String formattedSchedule = departureSchedule.format(formatter);
        return formattedSchedule;
    }

    public String getFlighDuration() {
        // converts Duration data type to String to be returned
        return flighDuration.toString();
    }

    // method
    public void addPassenger(int passengerID, int flightID) {
        passengers[passengerSize[flightID]][flightID] = passengerID;
        passengerSize[flightID]++;
    }

}
