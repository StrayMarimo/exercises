package Airlines;
import java.lang.Math;

public class Airlines {

    public static void main(String[] args) {

        // create objects for classes
        FlightsClass[] flights = createFlights();
        PassengersClass[] passengers = createPassengers();
        AirlinesClass airlines = new AirlinesClass();
        int totalPassengers = 60;
        int ctr = 0;

        do {
            // if there are still passengers waiting to be queued
            if (ctr != totalPassengers) {
                // then enqueue 6 passengers
                System.out.println("Enqueing passengers from " + ctr + " to " + (ctr + 5));
                for (int i = ctr; i < ctr + 6; i++) {

                    // determine where airline the passenger belongs 
                    // by getting the airline id where the flight of passenger belongs
                    int airlineID = flights[passengers[i].flightID].airlineID;

                    // call enqueue method
                    airlines.enqueue(passengers[i].passengerID, airlineID, passengers[i].getIsPriority());

                    // store id of passenger to list of passengers in the flight it belongs
                    flights[passengers[i].flightID].addPassenger(passengers[i].passengerID, passengers[i].flightID);
                }
                // print current queue status
                airlines.printOnQueue();
                ctr+=6;
            } 
            // dequeue one passenger on each airline
            System.out.println("Dequeing a passenger on each line: ");
            airlines.dequeue();

             // print current queue status
            airlines.printOnQueue();
            
            
        } while (!airlines.isEmpty() || ctr != totalPassengers);

        // print flight information for all flights
        for (FlightsClass f: flights) {
            int flightId =  f.flightID;
            System.out.println("Flight " + flightId);
            System.out.println("\tis domestic: " + f.getIsDomestic());
            System.out.println("\tlocation: " + f.getDepartureLocation());
            System.out.println("\tschedule: " + f.getDepartureSchedule());
            System.out.println("\tduration: " + f.getFlighDuration().substring(2));
            System.out.println("\tairline ID: " + f.airlineID);
            System.out.println();
            
            // print passenger information who is boarding on each flight
            int[][] flightPassengers = FlightsClass.passengers;
            int passengerSize = FlightsClass.passengerSize[f.flightID];
            if (passengerSize > 0) {
                System.out.println("Passenger/s on this flight:");
                for (int i = 0; i < passengerSize; i++) {
                    System.out.println("\t" + passengers[flightPassengers[i][flightId]].getName());
                    System.out.println("\t\tnationality: " + passengers[flightPassengers[i][flightId]].getNationality());
                    System.out.println("\t\ttype: " +  passengers[flightPassengers[i][flightId]].getFlightType());
                    System.out.println("\t\tclass: " +  passengers[flightPassengers[i][flightId]].getFlightClass());
                }
            } else {
                System.out.println("There are no passengers on this flight.");
            }
        }

    }

    // methods

    // creates 12 distinct flights
    static FlightsClass[] createFlights(){
        final int size = 12;
        FlightsClass[] flights = new FlightsClass[size];

        // dummy data that will be randomized
        String[] domesticLocations = {"Iloilo", "Cebu", "Davao"};
        String[] internationalLocations = {"Japan", "Singapore", "Taiwan"};
        String[] departureSchedule = {"2022-10-22 10:30", "2022-10-22 15:30",
                     "2022-10-22 01:30", "2022-10-22 18:30"};
        String[] domesticFlightDuration = {"PT1H20M", "PT1H25M", "PT1H55M"};
        String[] internationalFlightDuration = {"PT4H5M", "PT3H40M", "PT2H10M"}; 

        for (int i = 0; i < size; i ++) {
            // create Flight object and pass FlightID and AirlineID
            FlightsClass flight = new FlightsClass(i, ((int) Math.floor(i / 2.0)));

            int randomNumber = (int) (Math.random() * 3);
            // half of the flight is domestice while half is international
            if (i < 6) {
                // set random values for domestic flights
                flight.setIsDomestic(true);
                flight.setDepartureLocation(domesticLocations[randomNumber]);
                flight.setFlighDuration(domesticFlightDuration[randomNumber]);
                flight.setDepartureSchedule(departureSchedule[(int) (Math.random() * 2)]);
            } else {
                // set random values for international flights
                flight.setIsDomestic(false);
                flight.setDepartureLocation(internationalLocations[randomNumber]);
                flight.setFlighDuration(internationalFlightDuration[randomNumber]);
                flight.setDepartureSchedule(departureSchedule[2 + (int) (Math.random() * 2)]);
            }

            // store flight to array
            flights[i] = flight;
        }
        // return array of Flights with size 12
        return flights;
    }

    // creates 60 distinct passengers
    static PassengersClass[] createPassengers(){
        final int size = 60;
        PassengersClass[] passengers = new PassengersClass[size];

        // dummy data that will be randomized
        String[] flightTypes = {"non-stop", "connecting", "direct"};
        String[] flightClasses = {"first class", "business", "economy"};
        String[] nationalities = {"Filipino", "American", "Japanese", "Chinese", "Korean"};

        for (int i = 0; i < size; i++) {
            // create Passenger object and pass PassengerID and FlightID
            PassengersClass passenger = new PassengersClass(i, ((int) (Math.random() * 12)));
            passenger.setIsPriority(((int) (Math.random() * 5)) == 0);
            passenger.setName("Passenger " + passenger.passengerID);
            passenger.setNationality(nationalities[(int) (Math.random() * 5)]);
            passenger.setFlightType(flightTypes[(int) (Math.random() * 3)]);
            passenger.setFlightClass(flightClasses[(int) (Math.random() * 3)]);
            
            // store passenger to array
            passengers[i] = passenger;
        }

        // return array of Passengers with size 60
        return passengers;
    }
}
