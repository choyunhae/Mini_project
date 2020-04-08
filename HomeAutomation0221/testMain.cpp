#include "HomeAutomation.h"
#include "Power.h"

int menu(char **menuList, int menuCnt); // ���޵� �޴��� ����ϰ� ��Ȯ�� �޴���ȣ�� �����ϴ� �Լ�
int controlMenuSelect(string message, int menuCnt); // ������ǰ�� ���º��� ó���� ���� �޴� �Լ�
void displayTitle(string title); // ó������ ���� ����ϱ� ���� Ÿ��Ʋ ����Լ� 
void screen(HomeAutomation &rHa, Power &rPw); // �ָ޴��� ����ϰ� �޴��� ���ù޾� �ݺ������� �ָ޴��� ó���ϴ� �Լ�
void listDisplayAppliance(HomeAutomation &rHa); // ��ϵ� ������ǰ�� �������
void controlAppliance(HomeAutomation &rHa); // ��ϵ� ������ǰ �����ϱ�
void addAppliance(HomeAutomation &rHa); // ������ǰ ���
void deleteAppliance(HomeAutomation &rHa); // ������ǰ ����
void powerDisplay(Power &rPw, HomeAutomation &rHa);  // ���¼Ҹ� ���
int inputInteger(char *message);  //  message�� ����ϰ� ������ �Է� �޾� ����(����, �Ǽ��� ���� ó��)
int inputInteger(string message); //  message�� ����ϰ� ������ �Է� �޾� ����(����, �Ǽ��� ���� ó��)
void myFlush();  // cin�Է� ���۸� ��� ���� fail���¸� �ʱ���·� �缳��

int main()
{
	HomeAutomation homeAuto;
	Power power;
	screen(homeAuto, power);
	getchar(); getchar();
	return 0;
}

void screen(HomeAutomation &rHa, Power &rPw)
{
	char *menuList[] = { "������ǰ ����Ȯ�� ", "������ǰ ���� ", "������ǰ ��� ", "������ǰ ���� ", "���� " };
	int menuCnt = sizeof(menuList) / sizeof(menuList[0]);
	int menuNum;

	displayTitle("Ȩ �ɾ�ý��� ����");
	while (true)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt) { break; }
		switch (menuNum)
		{
		case 1: listDisplayAppliance(rHa); break;
		case 2: controlAppliance(rHa); break;
		case 3: addAppliance(rHa); break;
		case 4: deleteAppliance(rHa); break;
		}
	}
	powerDisplay(rPw, rHa);                    // �Ҹ� ���·� ���
	displayTitle("Ȩ �ɾ�ý��� ����");
	return;
}
void listDisplayAppliance(HomeAutomation &rHa) // ��ϵ� ������ǰ�� �������
{
	displayTitle("������ǰ ���� ����");
	if (rHa.getApplianceCnt() == 0)
	{
		cout << "��ϵ� ���� ��ǰ�� �����ϴ�" << endl;
	}
	else
	{
		rHa.listDisplayAppliance();
	}
	displayTitle("������ǰ ���� ���� ����");
}
void controlAppliance(HomeAutomation &rHa) // ��ϵ� ������ǰ �����ϱ�
{
	string machineName;  // ��ǰ��
	bool res;

	displayTitle("������ǰ ���� �ϱ�");
	if (rHa.getApplianceCnt() == 0)
	{
		cout << "��ϵ� ������ǰ�� �����ϴ�. ������ǰ�� ���� ����ϼ���." << endl;
		return;
	}

	cout << "* ������ ��ǰ�� �Է� : ";
	cin >> machineName;
	res = rHa.controlAppliance(machineName);
	if (res)
	{
		cout << "���� ��ǰ�� : " << machineName << "�� ��� �Ϸ�Ǿ����ϴ�." << endl << endl;
	}
	else
	{
		cout << "���� ��ǰ�� : " << machineName << "�� ��� �����Ͽ����ϴ�." << endl << endl;
	}
}
void addAppliance(HomeAutomation &rHa) // ������ǰ ���
{
	string machineName;  // ��ǰ��
	int powerConsumption; // �ð��� ���¼Ҹ�
	Appliance *ap;  // ������ǰ Ŭ������ ������ ����
	bool res;

	displayTitle("������ǰ ��� �ϱ�");
	string applianceList = "1.��� / 2.�ó���� / 3.��Ź�� : ";
	int applianceNum;

	applianceNum = controlMenuSelect(applianceList, 3);
	cout << "* ��ǰ�� �Է�( ��)ū���, ��Ź�� ��) : ";
	cin >> machineName;
	powerConsumption = inputInteger("* ��ǰ ���¼Ҹ� �Է�(Kw/H) : ");

	switch (applianceNum)
	{
	case 1: ap = new RiceCooker(machineName, powerConsumption); break;
	case 2: ap = new AirConditioner(machineName, powerConsumption); break;
	case 3: ap = new Washer(machineName, powerConsumption); break;
	}
	res = rHa.addAppliance(ap);
	if (res)
	{
		cout << "���� ��ǰ�� : " << machineName << "�� ����� �Ϸ�Ǿ����ϴ�." << endl << endl;
	}
	else
	{
		cout << "���� ��ǰ�� : " << machineName << "�� ����� �����Ͽ����ϴ�." << endl << endl;
	}
}
void deleteAppliance(HomeAutomation &rHa) // ������ǰ ����
{
	string machineName;  // ��ǰ��
	bool res;

	displayTitle("������ǰ ���� �ϱ�");

	cout << "* ��ǰ�� �Է�( ��)�Ž�����, ��Ź�� ��) : ";
	cin >> machineName;

	res = rHa.deleteAppliance(machineName);
	if (res)
	{
		cout << "���� ��ǰ�� : " << machineName << "�� ������ �Ϸ�Ǿ����ϴ�." << endl << endl;
	}
	else
	{
		cout << "���� ��ǰ�� : " << machineName << "�� ������ �����Ͽ����ϴ�." << endl << endl;
	}
}

void powerDisplay(Power &rPw, HomeAutomation &rHa)  // ���¼Ҹ� ���
{
	int totalConsumption;

	totalConsumption = rPw.calPowerConsumption(rHa);
	cout << "������ǰ �� ���¼Ҹ� : " << totalConsumption << endl << endl;
}

int controlMenuSelect(string message, int menuCnt)
{
	int menuNum;

	while (true)
	{
		menuNum = inputInteger(message);
		if (menuNum>0 && menuNum <= menuCnt){ break; }
	}
	return menuNum;
}

int menu(char **menuList, int menuCnt)
{
	int i;
	int menuNum = 0; /* �Էµ� �޴� ��ȣ ���� ����*/

	cout << endl << "==================================" << endl;
	for (i = 0; i<menuCnt; i++)
	{
		cout << i + 1 << "." << menuList[i] << endl;
	}
	cout << "==================================" << endl;
	while (menuNum<1 || menuNum>menuCnt)  /* ���� ���� ��ȣ�� �Էµ� �� ���� �ݺ�*/
	{
		menuNum = inputInteger("# �޴���ȣ�� �Է��ϼ��� : ");

	}
	return menuNum;
}
void displayTitle(string title) // ȭ�� Ÿ��Ʋ ��� �Լ�
{
	cout << endl << "------------------------------" << endl;
	cout << "    " << title << endl;
	cout << "------------------------------" << endl;
}

// message�� ����ϰ� ������ �Է� �޾� ����(����, �Ǽ��� ���� ó��)
int inputInteger(char *message)
{
	int number;

	while (1){
		cout << message;
		cin >> number;

		if (cin.get() == '\n'){
			return number;
		}

		myFlush();
	}
}

// message�� ����ϰ� ������ �Է� �޾� ����(����, �Ǽ��� ���� ó��)
int inputInteger(string message)
{
	int number;

	while (1){
		cout << message;
		cin >> number;

		if (cin.get() == '\n'){
			return number;
		}

		myFlush();
	}
}

// ��� : cin�Է� ���۸� ��� ���� fail���¸� �ʱ���·� �缳��
void myFlush()
{
	cin.clear();  // ������ �����Ǿ��ִ� flag����� ���� 0���� ���ʱ�ȭ
	while (cin.get() != '\n');  // ���๮�ڰ� ���ö����� ���۳��� ��� ���� ����
}
