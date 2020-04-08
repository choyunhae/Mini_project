#include "Appliance.h"

time_t currentTime()
{
   time_t currentTime;
   time(&currentTime);
   return currentTime;
}
Appliance::Appliance()
{
   this->machineName = "";
   this->powerConsumption = 0;
   this->powerFlag = false;
   this->startHour = 0;
   this->useHour = 0;
}
Appliance::Appliance(string machineName, int powerConsumption, bool powerFlag, time_t startHour, time_t useHour)
{
   this->machineName = machineName;
   this->powerConsumption = powerConsumption;
   this->powerFlag = powerFlag;
   this->startHour = startHour;
   this->useHour = useHour;
}
string Appliance::getMachineName()const
{
   return this->machineName;
}
bool Appliance::getPowerFlag()const
{
   return this->powerFlag;
}
int Appliance::getPowerConsumption()const
{
   return this->powerConsumption;
}
time_t Appliance::getStartHour()
{
   return this->startHour;
}
time_t Appliance::getUseHour()
{
   return this->useHour;
}
void Appliance::setMachineName(string machineName)
{
   this->machineName = machineName;
}
void Appliance::setPowerFlag(bool powerFlag)
{
   this->powerFlag = powerFlag;
}
void Appliance::setPowerConsumption(int powerConsumption)
{
   this->powerConsumption = powerConsumption;
}
bool Appliance::turnOn()
{
   time_t Time;
   if (powerFlag == false)
   {
      this->powerFlag = true;
      Time = currentTime();
      this->startHour = Time;
      return true;
   }
   else return false;
}
bool Appliance::turnOff()
{
   if (powerFlag == true)
   {
      this->powerFlag = false;
      time_t Time;
      Time = currentTime();
      //Usemin += startHour - Time;
      //this->useHour = Usemin / 10;
      useHour += Time-this->startHour;
	  useHour /= 10;

      return true;
   }
   else return false;
}
