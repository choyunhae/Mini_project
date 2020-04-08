#include "HomeAutomation.h"
#include "Power.h"

int Power::calPowerConsumption(HomeAutomation &rHa)
{

	int i;
	int totPower = 0;
	int power = 0;

	for (i = 0; i < rHa.applianceCnt; i++)
	{
		if (rHa.applianceArray[i]->getPowerFlag() == false)
		{
			power = rHa.applianceArray[i]->getPowerConsumption()*rHa.applianceArray[i]->getUseHour();
			totPower += power;
		}
	}

	return totPower;
}