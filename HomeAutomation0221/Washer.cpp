#include "Washer.h"

Washer::Washer() :Appliance()
{
	this->machineState = 1;
}
Washer::Washer(string machineName, int powerConsumption)
: Appliance(machineName, powerConsumption)
{
	this->machineState = 1;
}
int Washer::getMachineState()const
{
	return machineState;
}
void Washer::setMachineState(int machineState)
{
	this->machineState = machineState;
}
void Washer::stateView()
{
	cout << "제품명 : " << getMachineName();
	if (this->getPowerFlag() == true)
	{
		cout << "(ON)" << " " << "설정상태 : ";
		if (this->machineState == 1){
			cout << "무동작";
		}
		else if (this->machineState == 2)
		{
			cout << "일반빨래";
		}
		else if (this->machineState == 3)
		{
			cout << "삶은빨래";
		}
		else if (this->machineState == 4)
		{
			cout << "건조";
		}
		cout << endl;
	}
	if (this->getPowerFlag() == false)
	{
		cout << "(OFF)" << endl;
	}
}