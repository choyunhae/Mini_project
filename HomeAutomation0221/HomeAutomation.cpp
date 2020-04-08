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
	cout << "**정말로 삭제하시겠습니까?(Y/N) : ";
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
	if (applianceCnt == 0){ cout << "등록된 가전제품이 없습니다." << endl; }
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
		cout << "등록된 가전제품이 없습니다. 가전제품을 먼저 등록하세요"
			<< endl;
	}
	for (i = 0; i < applianceCnt; i++)
	{
		if (applianceArray[i]->getMachineName() == machineName)
			break;
	}
	if (i == applianceCnt)
	{
		cout << "**해당하는 제품이 존재하지 않습니다." << endl;
		return false;
	}
	if (applianceArray[i]->getPowerFlag() == false)
	{
		cout << "전원을 켜시겠습니까?(Y/N) : ";
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
		cout << "1.무동작 / 2.일반빨래 / 3.삶은빨래 / 4.건조 / 5.끄기 : ";
			cin >> num;
			while (num<1 || num>5)
			{
				cout << "1.무동작 / 2.보온 / 3.밥짓기 / 4.데우기 / 5.끄기 : ";
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
		cout << "1.송풍 / 2.냉방 / 3.난방 / 4.끄기 : ";
		cin >> num;
		dynamic_cast<AirConditioner *>(ap)->setMachineState(num);
		while (num<1 || num>4)
		{
			cout << "1.송풍 / 2.냉방 / 3.난방 / 4.끄기 : ";
			cin >> num;
		}
		if (num >= 1 && num <= 3){		
			
			while (1){
				cout <<  "1.온도 올리기 / 2.온도 내리기 / 3.온도조절 종료 : " ;
					cin >> n;
					while (n<1|| n>3)
					{
						cout << "1.온도 올리기 / 2.온도 내리기 / 3.온도조절 종료 : " ;
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
		cout << "1.무동작 / 2.보온 / 3.밥짓기 / 4.데우기 / 5.끄기 :  ";
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
			cout << "1.무동작 / 2.보온 / 3.밥짓기 / 4.데우기 / 5.끄기 : ";
			cin >> num;
		}
		
	}

	ap->stateView();
}
