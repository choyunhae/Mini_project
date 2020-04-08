#include "RiceCooker.h"

RiceCooker::RiceCooker() :Appliance()
{
	this->machineState = 1;
}
RiceCooker::RiceCooker(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption)
{
	this->machineState = 1;
}
int RiceCooker::getMachineState()const
{
	return this->machineState;
}
void RiceCooker::setMachineState(int machineState)
{
	this->machineState = machineState;
}
void RiceCooker::stateView()
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
			cout << "보온";
		}
		else if (this->machineState == 3)
		{
			cout << "밥짓기";
		}
		else if (this->machineState == 4)
		{
			cout << "데우기";
		}
		cout << endl;
	}
	if (this->getPowerFlag() == false)
	{
		cout << "(OFF)" << endl;
	}

}