#include <iostream>
using namespace std;

class CPlayer {public:	virtual void Attack() { cout << "Player Normal Atk" << endl; }};

template <typename T>
class CAtkDecorator : public T
{
private:
	T* pComponent;
	char strName[32];
public:
	virtual void Attack()
	{
		cout << strName << endl;
		if (pComponent)
			pComponent->Attack();
	}
public:
	CAtkDecorator(T* pObj, const char* pName) {
		pComponent = pObj;
		strcpy_s(strName, 32, pName);
	}
	virtual ~CAtkDecorator() 
	{
		if (pComponent) 
			delete pComponent;
	}
};


int main()
{
	CPlayer* pPlayer = new CPlayer;
	CPlayer* pPlayerAtk1 = new CAtkDecorator<CPlayer>(pPlayer, "pPlayerAtk1");
	CPlayer* pPlayerAtk2 = new CAtkDecorator<CPlayer>(pPlayerAtk1, "pPlayerAtk2");
	pPlayerAtk2->Attack();
	delete(pPlayer);
	delete(pPlayerAtk1);
	delete(pPlayerAtk2);
}