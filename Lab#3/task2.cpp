#include <iostream>

class WaterBottle {
private:
    std::string m_company;
    std::string m_color;
    int m_capacityLiters;
    int m_capacityMilliliters;

public:
    // Constructor
    WaterBottle(std::string company, std::string color, int capacityLiters, int capacityMilliliters) : 
        m_company(company), m_color(color), m_capacityLiters(capacityLiters), m_capacityMilliliters(capacityMilliliters) {}

    // Getter and setter methods
    std::string getCompany() const { return m_company; }
    void setCompany(const std::string& company) { m_company = company; }

    std::string getColor() const { return m_color; }
    void setColor(const std::string& color) { m_color = color; }

    int getCapacityLiters() const { return m_capacityLiters; }
    void setCapacityLiters(int capacityLiters) { m_capacityLiters = capacityLiters; }

    int getCapacityMilliliters() const { return m_capacityMilliliters; }
    void setCapacityMilliliters(int capacityMilliliters) { m_capacityMilliliters = capacityMilliliters; }

    // Method to update water capacity after consuming water in milliliters
    void consumeWater(int consumedMilliliters) {
        int totalCapacityMilliliters = m_capacityLiters * 1000 + m_capacityMilliliters;
        if (consumedMilliliters <= totalCapacityMilliliters) {
            totalCapacityMilliliters -= consumedMilliliters;
            m_capacityLiters = totalCapacityMilliliters / 1000;
            m_capacityMilliliters = totalCapacityMilliliters % 1000;
            std::cout << "Water consumed. Remaining capacity: " << m_capacityLiters << " liters and " 
                      << m_capacityMilliliters << " milliliters." << std::endl;
        } else {
            std::cout << "Cannot consume. Insufficient water in the bottle." << std::endl;
        }
    }
};

int main() {
    // Creating a water bottle object
    WaterBottle bottle("Acme", "Blue", 2, 500);

    // Displaying initial attributes
    std::cout << "Company: " << bottle.getCompany() << std::endl;
    std::cout << "Color: " << bottle.getColor() << std::endl;
    std::cout << "Capacity: " << bottle.getCapacityLiters() << " liters and " 
              << bottle.getCapacityMilliliters() << " milliliters." << std::endl;

    // Consuming water
    bottle.consumeWater(300); // Suppose 300 milliliters of water is consumed

    // Displaying updated capacity after consumption
    std::cout << "Updated Capacity: " << bottle.getCapacityLiters() << " liters and " 
              << bottle.getCapacityMilliliters() << " milliliters." << std::endl;

    return 0;
}

