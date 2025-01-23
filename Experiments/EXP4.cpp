#include <iostream>
using namespace std;

class Transportation {
public:
    // Calculate cost based on weight
    double calculateCost(double weight) {
        if (weight < 0.1 || weight > 50) {
            throw std::invalid_argument("Weight must be between 0.1 kg and 50 kg.");
        }

        if (weight <= 1.0) {
            return 5 + (2 * weight);
        } else if (weight <= 10.0) {
            return 10 + (1.5 * weight);
        } else {
            return 20 + (1 * weight);
        }
    }

    // Calculate cost based on dimensions
    double calculateCost(double length, double width, double height) {
        if (length < 10 || length > 200 || width < 10 || width > 100 || height < 10 || height > 50) {
            throw std::invalid_argument("Dimensions are out of range.");
        }

        double volume = (length / 100.0) * (width / 100.0) * (height / 100.0); // Convert to cubic meters

        if (volume < 0.1) {
            return 10 + (0.5 * volume);
        } else if (volume < 0.5) {
            return 15 + (0.25 * volume);
        } else {
            return 25 + (0.1 * volume);
        }
    }

    // Calculate cost based on package type and weight
    double calculateCost(const std::string& packageType, double weight) {
        if (weight < 0.1 || weight > 50) {
            throw std::invalid_argument("Weight must be between 0.1 kg and 50 kg.");
        }

        double cost = 0.0;

        if (packageType == "Ground") {
            cost = calculateGroundCost(weight);
        } else if (packageType == "Air") {
            cost = calculateAirCost(weight);
        } else if (packageType == "Express") {
            cost = calculateExpressCost(weight);
        } else {
            throw std::invalid_argument("Invalid package type");
        }

        return cost;
    }

    double calculateGroundCost(double weight) {
        if (weight <= 1.0) {
            return 5 + (2 * weight);
        } else if (weight <= 10.0) {
            return 10 + (1.5 * weight);
        } else {
            return 20 + (1 * weight);
        }
    }

    double calculateAirCost(double weight) {
        if (weight <= 1.0) {
            return 10 + (3 * weight);
        } else if (weight <= 10.0) {
            return 20 + (2 * weight);
        } else {
            return 30 + (1.5 * weight);
        }
    }

    double calculateExpressCost(double weight) {
        if (weight <= 1.0) {
            return 15 + (4 * weight);
        } else if (weight <= 10.0) {
            return 30 + (3 * weight);
        } else {
            return 40 + (2 * weight);
        }
    }
};

int main() {
    Transportation trans;

    try {
        // Test weight-based cost calculation
        std::cout << "Cost for shipping a package weighing 5 kg: $" 
                  << trans.calculateCost(5.0) << std::endl;

        // Test dimensions-based cost calculation
        std::cout << "Cost for shipping a package with dimensions 50 cm x 50 cm x 20 cm: $"
                  << trans.calculateCost(50.0, 50.0, 20.0) << std::endl;

        // Test package type and weight-based cost calculation
        std::cout << "Cost for shipping an Air package weighing 2 kg: $"
                  << trans.calculateCost("Air", 2.0) << std::endl;

        // Additional tests for Ground and Express packages
        std::cout << "Cost for shipping a Ground package weighing 8 kg: $"
                  << trans.calculateCost("Ground", 8.0) << std::endl;

        std::cout << "Cost for shipping an Express package weighing 12 kg: $"
                  << trans.calculateCost("Express", 12.0) << std::endl;

    } catch (const std::invalid_argument& s) {
        std::cout<< "Error: " << s.what() << std::endl;
    }

    return 0;
}
