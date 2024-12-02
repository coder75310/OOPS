#include <iostream>
using namespace std;

int main() {
    // Variables for rectangle
    float length, width, area;
    
    // Variables for triangle
    float side1, side2, side3, perimeter;

    // Input for rectangle
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the width of the rectangle: ";
    cin >> width;

    // Calculate area of rectangle
    area = length * width;
    cout << "The area of the rectangle is: " << area << endl;

    // Input for triangle
    cout << "Enter the length of the first side of the triangle: ";
    cin >> side1;
    cout << "Enter the length of the second side of the triangle: ";
    cin >> side2;
    cout << "Enter the length of the third side of the triangle: ";
    cin >> side3;

    // Calculate perimeter of triangle
    perimeter = side1 + side2 + side3;
    cout << "The perimeter of the triangle is: " << perimeter << endl;

    return 0;
}
