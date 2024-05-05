#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Define error messages
#define GPS_SIGNAL_LOSS_ERROR "GPS_SIGNAL_LOSS: Unable to determine current position"
#define DRONE_COMMUNICATION_ERROR "DRONE_COMMUNICATION_ERROR: Communication error with drone hardware"
#define DRONE_FLIGHT_LIMIT_ERROR "FLIGHT_LIMIT: Drone has reached maximum flight time"
#define DRONE_OUT_OF_RANGE_ERROR "OUT_OF_RANGE: Destination is out of drone's range"


struct Object {
    float x;
    float y;
    float z;
};


class Drone {
protected:
    float latitude;
    float longitude;
    float altitude;
    float speed;

public:
    Drone(float lat, float lon, float alt, float spd) : latitude(lat), longitude(lon), altitude(alt), speed(spd) {}

    void adjustAltitude(float meters) { altitude += meters;}
    void setSpeed(float spd) {speed = spd;}
    virtual void start() = 0;
};


class Flyable {
public:
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float lat, float lon, float alt) = 0;
};


class Scannable {
public:
    virtual void scanArea(float radius) = 0;
};


class ReconDrone : public Drone, public Flyable, public Scannable {
private:
    float cameraResolution;
    float maxFlightTime;

public:
    ReconDrone(float lat, float lon, float alt, float spd, float camRes, float maxTime)
        : Drone(lat, lon, alt, spd), cameraResolution(camRes), maxFlightTime(maxTime) {}

    void start() override {
        cout << "ReconDrone activated.. " << endl;
        cout << "Drone Camera Resolution [" << this->cameraResolution << "p]" << endl;
        cout << "Drone Max Flight Time [" << this->maxFlightTime << "s]" << endl << endl;
    }

    void takeoff() override {
        cout << "ReconDrone taking off...\n";
    }

    void land() override {
        cout << "ReconDrone landing...\n";
    }

    void navigateTo(float lat, float lon, float alt) override {
        // Check for GPS signal loss
        if (latitude == 0 && longitude == 0) {
            cout << "Error: " << GPS_SIGNAL_LOSS_ERROR << endl;
            return;
        }

        // Check for communication error with drone hardware
        if (altitude == 0) {
            cout << "Error: " << DRONE_COMMUNICATION_ERROR << endl;
            return;
        }

        // Calculate distance between current position and target position
        float dx = lat - latitude;
        float dy = lon - longitude;
        float dz = alt - altitude;
        float distance = sqrt(dx * dx + dy * dy + dz * dz);

        if (distance > maxFlightTime * speed) {
            cout << "Error: " << DRONE_OUT_OF_RANGE_ERROR << endl;
            return;
        }

        // Calculate estimated time to reach destination
        float estimatedTime = distance / speed;

        // Check if estimated time exceeds maximum flight time
        if (estimatedTime > maxFlightTime) {
            cout << "Error: " << DRONE_FLIGHT_LIMIT_ERROR << endl;
            return;
        }

        cout << "Navigating to coordinates (" << lat << ", " << lon << ", " << alt << ")...\n";
        cout << "Estimated time to reach destination: " << estimatedTime << " seconds\n";

        // Update drone's position
        latitude = lat;
        longitude = lon;
        altitude = alt;
    }

    void scanArea(float radius) override {
    if (latitude == 0 && longitude == 0) {
        cout << "Error: " << GPS_SIGNAL_LOSS_ERROR << endl;
        return;
    }

    // Check for communication error with drone hardware
    if (altitude == 0) {
        cout << "Error: " << DRONE_COMMUNICATION_ERROR << endl;
        return;
    }

    cout << "Scanning area within " << radius << "m radius...\n";
    cout << "Objects detected:\n";
    // Assume some objects in the environment
    vector<Object> objects = {
        {10, 20, 30},
        {-5, -10, 40},
        {50, 60, 70}
    };
    cout << "Drone position: (" << latitude << ", " << longitude << ", " << altitude << ")\n";
    for (const auto& obj : objects) {
        float dx = obj.x - latitude;
        float dy = obj.y - longitude;
        float dz = obj.z - altitude;
        float distance = sqrt(dx * dx + dy * dy + dz * dz);
        if (distance <= radius) {
            cout << "Object detected at (" << obj.x << ", " << obj.y << ", " << obj.z << ")\n";
        }
    }
}



};

int main() {
    cout << "\n\nCreator: Amna(23K-0066)" << endl << endl;
    ReconDrone drone(40.7, -74., 100, 10, 1080, 3600); // Initial position (latitude, longitude, altitude), speed, camera resolution, max flight time

    drone.start();
    drone.takeoff();
    drone.navigateTo(34.05, -137, 50);
    drone.scanArea(10);
    
    drone.navigateTo(34, 18.2, 150); 
    drone.scanArea(100); 

    drone.navigateTo(40.71, -74, 100);
    drone.land();


}