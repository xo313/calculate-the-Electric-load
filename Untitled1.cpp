#include <iostream>
#include <cmath>
using namespace std;

class power {
public:
    float powerKW;
    float current;
    string phaseType;
    float voltage;
    void calculate() {
        if (powerKW > 5) {
            phaseType = "3-Phase";
            voltage = 400;
            current = powerKW / (sqrt(3) * voltage * 0.8);
        } else {
            phaseType = "1-Phase";
            voltage = 220;
            current = powerKW / (voltage * 0.8);
        }
    }


    string suggestCableSize(float current) {
        if (current <= 10) return "1.5 mm";
        else if (current <= 16) return "2.5 mm";
        else if (current <= 25) return "4 mm";
        else if (current <= 32) return "6 mm";
        else if (current <= 40) return "10 mm";
        else if (current <= 63) return "16 mm";
        else return "Check engineering tables";
    }

};

// كلاس لحساب حجم القاطع الكهربائي المناسب
class ElectricLoad :public power {
public:
     string suggestBreakerSize(float current) {
        if (current <= 10) return "10 A";
        else if (current <= 16) return "16 A";
        else if (current <= 20) return "20 A";
        else if (current <= 25) return "25 A";
        else if (current <= 32) return "32 A";
        else if (current <= 40) return "40 A";
        else if (current <= 50) return "50 A";
        else if (current <= 63) return "63 A";
        else return "Special breaker needed";
    }
	void showResult() {
        cout << "\nPhase type: " << phaseType << endl;
        cout << "Calculated current: " << current << " A" << endl;
        cout << "Suggested cable size: " << suggestCableSize(current) << endl;
        cout << "Suggested circuit breaker: " <<suggestBreakerSize(current)<< endl;

    }
};

int main() {
       ElectricLoad load;
	   cout << "Enter electrical power (kW): ";
	   cin >> load.powerKW;


    load.calculate();
    load.showResult();
}
