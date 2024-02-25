#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum) {}
	int GetBullet(void) const
	{
		return bullet;
	}
	void Shot(void)
	{
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff) : handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}
	Police(Police& pman) : handcuffs(pman.handcuffs)
	{
		cout << "복사 생성자 호출" << endl;

		if (pman.pistol->GetBullet() > 0)
			pistol = new Gun(pman.pistol->GetBullet());
		else
			pistol = NULL;
	}
	void PutHandcuff(void)
	{
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot(void)
	{
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shot();
	}
	Police& operator=(const Police& ref)
	{
		cout << "대입 연산자 호출" << endl;

		if (pistol != NULL)
			delete pistol;

		handcuffs = ref.handcuffs;

		if (ref.pistol->GetBullet() > 0)
			pistol = new Gun(ref.pistol->GetBullet());
		else
			pistol = NULL;

		return *this;
	}
	~Police()
	{
		cout << "소멸자 호출" << endl;

		if (pistol != NULL)
			delete pistol;
	}
};

int main(void)
{
	Police pman1(5, 3);
	Police pman2(0, 3);
	Police pman3 = pman1;

	pman2 = pman1;
	return 0;
}