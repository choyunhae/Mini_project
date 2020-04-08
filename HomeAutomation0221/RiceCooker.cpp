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
	cout << "��ǰ�� : " << getMachineName();
	if (this->getPowerFlag() == true)
	{
		cout << "(ON)" << " " << "�������� : ";
		if (this->machineState == 1){
			cout << "������";
		}
		else if (this->machineState == 2)
		{
			cout << "����";
		}
		else if (this->machineState == 3)
		{
			cout << "������";
		}
		else if (this->machineState == 4)
		{
			cout << "�����";
		}
		cout << endl;
	}
	if (this->getPowerFlag() == false)
	{
		cout << "(OFF)" << endl;
	}

}