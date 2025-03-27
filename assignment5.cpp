#include <iostream>
#include <vector>
using namespace std;

// Base Class Ride
class Ride {
protected:
    int rideID;
    string pickupLocation, dropoffLocation;
    double distance;
public:
    Ride(int id, string pickup, string dropoff, double dist) 
        : rideID(id), pickupLocation(pickup), dropoffLocation(dropoff), distance(dist) {}
    virtual double fare() const = 0; // Pure virtual function
    virtual void rideDetails() const {
        cout << "Ride ID: " << rideID << ", Pickup: " << pickupLocation 
             << ", Dropoff: " << dropoffLocation << ", Distance: " << distance << " miles\n";
    }
    virtual ~Ride() {}
};

// StandardRide subclass
class StandardRide : public Ride {
public:
    StandardRide(int id, string pickup, string dropoff, double dist) 
        : Ride(id, pickup, dropoff, dist) {}
    double fare() const override {
        return distance * 2.0; // $2 per mile
    }
    void rideDetails() const override {
        Ride::rideDetails();
        cout << "Fare: $" << fare() << " (Standard Ride)\n";
    }
};

// PremiumRide subclass
class PremiumRide : public Ride {
public:
    PremiumRide(int id, string pickup, string dropoff, double dist) 
        : Ride(id, pickup, dropoff, dist) {}
    double fare() const override {
        return distance * 3.5; // $3.5 per mile
    }
    void rideDetails() const override {
        Ride::rideDetails();
        cout << "Fare: $" << fare() << " (Premium Ride)\n";
    }
};

// Driver class
class Driver {
private:
    int driverID;
    string name;
    double rating;
    vector<Ride*> assignedRides;
public:
    Driver(int id, string driverName, double driverRating) 
        : driverID(id), name(driverName), rating(driverRating) {}
    void addRide(Ride* ride) {
        assignedRides.push_back(ride);
    }
    void getDriverInfo() const {
        cout << "Driver ID: " << driverID << "\n";
        cout << "Name: " << name << "\n";
        cout << "Rating: " << rating << "\n";
        cout << "Completed Rides: " << assignedRides.size() << "\n";
    }
};

// Rider class
class Rider {
private:
    int riderID;
    string name;
    vector<Ride*> requestedRides;
public:
    Rider(int id, string riderName) : riderID(id), name(riderName) {}
    void requestRide(Ride* ride) {
        requestedRides.push_back(ride);
    }
    void viewRides() const {
        cout << "Rider " << name << "'s Ride History:\n";
        for (const auto& ride : requestedRides) {
            ride->rideDetails();
        }
    }
};

int main() {
    StandardRide ride1(1, "Downtown ", "Airport", 10);
    PremiumRide ride2(2, "College", "Hilton garden", 5);
    
    Rider rider(101, "Bhavna");
    rider.requestRide(&ride1);
    rider.requestRide(&ride2);
    
    Driver driver(201, "Aman", 4.8);
    driver.addRide(&ride1);
    driver.addRide(&ride2);
    
    cout << "\n-- Rider's Rides --\n";
    cout << "\n==========================\n";
    rider.viewRides();
    
    cout << "\n-- Driver Info --\n";
    cout << "\n==========================\n";
    driver.getDriverInfo();
    
    return 0;
}