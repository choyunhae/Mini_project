#include "HomeAutomation.h"

HomeAutomation::HomeAutomation()
{
	int i;
	for (i = 0; i < APPLIANCE_MAX_CNT; i++)
	{
		applianceArray[i] = 0;
	}
	applianceCnt = 0;
}
HomeAutomation::HomeAutomation(const HomeAutomation &r)
{
	int i;
	this->applianceCnt = r.applianceCnt;
	for (i = 0; i < applianceCnt; i++)
	{
		if (dynamic_cast<RiceCooker *>(r.applianceArray[i]))
		{
			applianceArray[i] = new RiceCooker;
		}
		if (dynamic_cast<AirConditioner *>(r.applianceArray[i]))
		{
			applianceArray[i] = new AirConditioner;
		}
		if (dynamic_cast<Washer *>(r.applianceArray[i]))
		{
			applianceArray[i] = new AirConditioner;
		}
		applianceArray[i] = r.applianceArray[i];
	}
}
HomeAutomation::~HomeAutomation()
{
	int i;
	for (i = 0; i < applianceCnt; i++)
	{
		delete applianceArray[i];
	}
}
Appliance **HomeAutomation::getApplianceArray()
{
	return applianceArray;
}
int HomeAutomation::getApplianceCnt()const
{
	return applianceCnt;
}
HomeAutomation&HomeAutomation::operator=(const HomeAutomation &r)
{
	int i;
	if (this == &r)return *this;
	for (i = 0; i < applianceCnt; i++)
	{
		delete applianceArray[i];
	}
	for (i = 0; i < applianceCnt; i++)
	{
		if (dynamic_cast<RiceCooker *>(r.applianceArray[i]))
		{
			applianceArray[i] = new RiceCooker;
		}
		if (dynamic_cast<AirConditioner *>(r.applianceArray[i]))
		{
			applianceArray[i] = new AirConditioner;
		}
		if (dynamic_cast<Washer *>(r.applianceArray[i]))
		{
			applianceArray[i] = new AirConditioner;
		}
		applianceArray[i] = r.applianceArray[i];
	}
	applianceCnt = r.applianceCnt;
	return *this;
}
bool HomeAutomation::addAppliance(Appliance *ap)
{
	int i;
	if (applianceCnt >= APPLIANCE_MAX_CNT)return false;
	for (i = 0; i < applianceCnt; i++)
	{
		if (applianceArray[i]->getMachineName() == ap->getMachineName())
		{
			return false;
		}
	}
	applianceArray[applianceCnt] = ap;
	applianceCnt++;
	return true;
}
int HomeAutomation::searchMachine(string machineName)
{
	int i, index;
	for (i = 0; i < applianceCnt; i++)
	{
		if (applianceArray[i]->getMachineName() == machineName)
		{
			index = i;
		}
		else if (i == applianceCnt)index = -1;
	}
	return index;
}
bool HomeAutomation::deleteAppliance(string machineName)
{
	int i, j;
	char ch;
	for (i = 0; i < applianceCnt; i++)
	{
		if (applianceArray[i]->getMachineName() == machineName)
			break;
	}
	if (i == applianceCnt)return false;
	cout << "**������ �����Ͻðڽ��ϱ�?(Y/N) : ";
	cin >> ch;
	if (ch == 'N')return false;
	for (j = i; j < applianceCnt; j++)
	{
		//delete applianceArray[j];
		applianceArray[j] = applianceArray[j + 1];
	}
	applianceCnt--;
	return true;
}
void HomeAutomation::listDisplayAppliance()
{
	if (applianceCnt == 0){ cout << "��ϵ� ������ǰ�� �����ϴ�." << endl; }
	for (int i = 0; i < applianceCnt; i++)
	{
		applianceArray[i]->stateView();
	}
}
bool HomeAutomation::controlAppliance(string machineName)
{
	int i;
	char ch;
	if (applianceCnt == 0)
	{
		cout << "��ϵ� ������ǰ�� �����ϴ�. ������ǰ�� ���� ����ϼ���"
			<< endl;
	}
	for (i = 0; i < applianceCnt; i++)
	{
		if (applianceArray[i]->getMachineName() == machineName)
			break;
	}
	if (i == applianceCnt)
	{
		cout << "**�ش��ϴ� ��ǰ�� �������� �ʽ��ϴ�." << endl;
		return false;
	}
	if (applianceArray[i]->getPowerFlag() == false)
	{
		cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
		cin >> ch;
		if (ch == 'Y'||ch=='y'){
			applianceArray[i]->turnOn();
			setStateAppliance(applianceArray[i]);
		}
		return true;
	}
	if (applianceArray[i]->getPowerFlag() == true)
	{
		setStateAppliance(applianceArray[i]);
	}
	return true;
}
void HomeAutomation::setStateAppliance(Appliance *ap)
{
	
	int num=0;
	int n = 0;
	if (dynamic_cast<Washer*>(ap))
	{
		cout << "1.������ / 2.�Ϲݻ��� / 3.�������� / 4.���� / 5.���� : ";
			cin >> num;
			while (num<1 || num>5)
			{
				cout << "1.������ / 2.���� / 3.������ / 4.����� / 5.���� : ";
				cin >> num;
			}
			if (num >= 1 && num <= 5)
			{
				dynamic_cast<Washer*>(ap)->setMachineState(num);
			}
			else if (num == 5){
				dynamic_cast<RiceCooker*>(ap)->turnOff();
			}
			
	
	}
	else if (dynamic_cast<AirConditioner*>(ap))
	{
		cout << "1.��ǳ / 2.�ù� / 3.���� / 4.���� : ";
		cin >> num;
		dynamic_cast<AirConditioner *>(ap)->setMachineState(num);
		while (num<1 || num>4)
		{
			cout << "1.��ǳ / 2.�ù� / 3.���� / 4.���� : ";
			cin >> num;
		}
		if (num >= 1 && num <= 3){		
			
			while (1){
				cout <<  "1.�µ� �ø��� / 2.�µ� ������ / 3.�µ����� ���� : " ;
					cin >> n;
					while (n<1|| n>3)
					{
						cout << "1.�µ� �ø��� / 2.�µ� ������ / 3.�µ����� ���� : " ;
						cin >> n;
					}
				if (n == 1){ ++(*dynamic_cast<AirConditioner *>(ap)); }
				else if (n == 2){ --(*dynamic_cast<AirConditioner*>(ap)); }
				else if (n== 3){ break; }
			}
			
		}
		else if (n == 4)
			dynamic_cast<AirConditioner*>(ap)->turnOff();
	}
	else if (dynamic_cast<RiceCooker*>(ap))
	{
		cout << "1.������ / 2.���� / 3.������ / 4.����� / 5.���� :  ";
		cin >> num;
		if (num >= 1 && num <= 4)
		{
			dynamic_cast<RiceCooker*>(ap)->setMachineState(num);
		}
		else if (num == 5){
			dynamic_cast<RiceCooker*>(ap)->turnOff();
		}
		while (num<1 || num>5)
		{
			cout << "1.������ / 2.���� / 3.������ / 4.����� / 5.���� : ";
			cin >> num;
		}
		
	}

	ap->stateView();
}
