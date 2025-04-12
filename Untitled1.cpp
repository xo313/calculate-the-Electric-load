#include <iostream>
#include <cmath>
using namespace std;

class ElectricLoad {
private:
    float powerKW;
    float current;
    string phaseType;
    float voltage;

public:
    ElectricLoad(float p) {
        powerKW = p;
        current = 0;
        phaseType = "";
        voltage = 0;
    }

    void calculate() {
        float powerW = powerKW * 1000;

        if (powerW > 5000) {
            phaseType = "3-Phase";
            voltage = 400;
            current = powerW / (sqrt(3) * voltage * 0.8);
        } else {
            phaseType = "1-Phase";
            voltage = 220;
            current = powerW / (voltage * 0.8);
        }
    }

    void showResult() {
        cout << "\nPhase type: " << phaseType << endl;
        cout << "Calculated current: " << current << " A" << endl;
        cout << "Suggested cable size: " << suggestCableSize(current) << endl;
    }

    string suggestCableSize(float current) {
        if (current <= 10) return "1.5 mm";
        else if (current <= 16) return "2.5 mm";
        else if (current <= 25) return "4 mm";
        else if (current <= 32) return "6 mm";
        else if (current <= 40) return "10 mm";
        else if (current <= 63) return "16 mm";
    }
};

int main() {
    float power;
    cout << "Enter electrical power (kW): ";
    cin >> power;

    ElectricLoad load(power);
    load.calculate();
    load.showResult();

    return 0;
}