#include <iostream>

using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car(int gasoline)
		: gasolineGauge(gasoline)
	{
		cout << "가솔린 충전!" << endl;
	}
	int GetGasGauge(void)
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int gasoline, int electric)
		: Car(gasoline), electricGauge(electric)
	{
		cout << "전기 충전!" << endl;
	}
	int GetElecGauge(void)
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gasoline, int electric, int water)
		: HybridCar(gasoline, electric), waterGauge(water)
	{
		cout << "물 충전!" << endl << endl;
	}
	void ShowCurrentGauge(void)
	{
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};

int main(void)
{
	HybridWaterCar HWcar(100, 200, 300);

	HWcar.ShowCurrentGauge();
	return 0;
}