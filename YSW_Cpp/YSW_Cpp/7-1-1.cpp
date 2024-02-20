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
		cout << "���ָ� ����!" << endl;
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
		cout << "���� ����!" << endl;
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
		cout << "�� ����!" << endl << endl;
	}
	void ShowCurrentGauge(void)
	{
		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
	}
};

int main(void)
{
	HybridWaterCar HWcar(100, 200, 300);

	HWcar.ShowCurrentGauge();
	return 0;
}