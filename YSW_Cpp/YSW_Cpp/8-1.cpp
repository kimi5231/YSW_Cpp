#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

namespace RISK_LEVEL
{
	enum {RISK_A = 3, RISK_B = 2, RISK_C = 1};
}

class Employee
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName(void) const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay(void) const = 0;
	virtual void ShowSalaryInfo(void) const = 0;
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)
		:Employee(name), salary(money)
	{}
	int GetPay(void) const
	{
		return salary;
	}
	void ShowSalaryInfo(void) const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay)
		:Employee(name), workTime(0), payPerHour(pay)
	{}
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	int GetPay(void) const
	{
		return workTime * payPerHour;
	}
	void ShowSalaryInfo(void) const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SaleWorker : public PermanentWorker
{
private:
	int saleResult;
	double bonusRatio;
public:
	SaleWorker(const char* name, int money, double ratio)
		:PermanentWorker(name, money), saleResult(0), bonusRatio(ratio)
	{}
	void AddSalesResult(int value)
	{
		saleResult += value;
	}
	int GetPay(void) const
	{
		return PermanentWorker::GetPay() + (int)(saleResult * bonusRatio);
	}
	void ShowSalaryInfo(void) const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class ForeignSalesWorker : public SaleWorker
{
private:
	int riskLevel;
public:
	ForeignSalesWorker(const char*name, int money, double ratio, int risk)
		:SaleWorker(name, money, ratio), riskLevel(risk)
	{}
	int GetPay(void) const
	{
		return SaleWorker::GetPay() + SaleWorker::GetPay() * riskLevel * 0.1;
	}
	void ShowSalaryInfo(void) const
	{
		ShowYourName();
		cout << "salary: " << SaleWorker::GetPay() << endl;
		cout << "risk pay: " << SaleWorker::GetPay() * riskLevel * 0.1 << endl;
		cout << "sum: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) {}
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo(void) const
	{
		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();
	}
	void ShowTotalSalary(void) const
	{
		int sum = 0;
		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();

		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	EmployeeHandler handler;

	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	handler.ShowAllSalaryInfo();
	return 0;
}