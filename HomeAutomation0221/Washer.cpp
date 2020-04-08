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
	cout << "��ǰ�� : " << getMachineName();
	if (this->getPowerFlag() == true)
	{
		cout << "(ON)" << " " << "�������� : ";
		if (this->machineState == 1){
			cout << "������";
		}
		else if (this->machineState == 2)
		{
			cout << "�Ϲݻ���";
		}
		else if (this->machineState == 3)
		{
			cout << "��������";
		}
		else if (this->machineState == 4)
		{
			cout << "����";
		}
		cout << endl;
	}
	if (this->getPowerFlag() == false)
	{
		cout << "(OFF)" << endl;
	}
}