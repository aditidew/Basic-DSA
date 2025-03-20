#include <iostream>
using namespace std;

int main() {
    int choice;
    float tempInput;
    float tempInCelsius, tempInFahrenheit, tempInKelvin;

    cout << "Enter the Temperature: ";
    cin >> tempInput;

    cout << "Choose the temperature scale: " << endl;
    cout << "1 for Celsius" << endl;
    cout << "2 for Fahrenheit" << endl;
    cout << "3 for Kelvin" << endl;

    cin >> choice;

    switch (choice) {
        case 1: // Celsius to Fahrenheit and Kelvin
            tempInCelsius = tempInput;
            tempInFahrenheit = (tempInCelsius * (9.0 / 5.0)) + 32;
            tempInKelvin = tempInCelsius + 273.15;
            cout << "Temperature in Fahrenheit: " << tempInFahrenheit << endl;
            cout << "Temperature in Kelvin: " << tempInKelvin << endl;
            break;

        case 2: // Fahrenheit to Celsius and Kelvin
            tempInFahrenheit = tempInput;
            tempInCelsius = (tempInFahrenheit - 32) * (5.0 / 9.0);
            tempInKelvin = tempInCelsius + 273.15;
            cout << "Temperature in Celsius: " << tempInCelsius << endl;
            cout << "Temperature in Kelvin: " << tempInKelvin << endl;
            break;

        case 3: // Kelvin to Celsius and Fahrenheit
            tempInKelvin = tempInput;
            tempInCelsius = tempInKelvin - 273.15;
            tempInFahrenheit = (tempInCelsius * (9.0 / 5.0)) + 32;
            cout << "Temperature in Celsius: " << tempInCelsius << endl;
            cout << "Temperature in Fahrenheit: " << tempInFahrenheit << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0; // Indicate successful execution
}
