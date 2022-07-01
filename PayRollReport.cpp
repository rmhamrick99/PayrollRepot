#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

//** Heading Lines

char PT1[] = "				PAYROLL";
char HL1[] = "Branch#  Division#  Dept#  FName  LName   Hours Worked    Pay rate    ";
char HL2[] = "---------------------------------------------------------------------";

class report
{
private:
	


public:
	void mainline(void);
	void OpenFile(void);
	void PrnHeadings(void);
	void readIt();
	void writeIt();
	void initialization();

	ifstream payrollFile;
	bool bEndFlag;

	int index;
	int branchNum;
	int divNum;
	int dptNum;
	char employee_FN[9];
	char employee_LN[9];
	int hoursWorked;
	float hourlyPay;
};

int main()
{
	report p1;
	p1.mainline();

	system("pause");
	

}

void report::mainline()
{
	initialization();
	writeIt();

}
void report::OpenFile(void)
{
	payrollFile.open("PayRollReport.dat");
	if (payrollFile.fail())
		cout << " Payroll file open fails" << endl;
	return;
}
void report:: PrnHeadings(void)
{
	cout << PT1 << endl;    //print page title 1
	cout << endl << endl;	//triple space
	cout << HL1 << endl;	//print heading line 1
	cout << HL2 << endl;	//print heading line 2
	return;
}
void report::readIt()
{

	payrollFile >> branchNum>> divNum>>dptNum>>employee_FN >> employee_LN
		>> hoursWorked >> hourlyPay;
	if (payrollFile.eof() == true)
	{
		bEndFlag = true;
	}

	return;
}

void report::writeIt()
{
	cout << setw(5) << branchNum << setw(8) << divNum << setw(10) << dptNum
		<< setw(8) << employee_FN << setw(9) << employee_LN
		<< setw(8) << hoursWorked 
		<< setiosflags(ios::fixed)
		<< setiosflags(ios::showpoint)
		<< setw(14) << setprecision(2) << hourlyPay << endl;
	return;
}
void report::initialization()
{
	index = 0;
	bEndFlag = true;
	OpenFile();
	if (!payrollFile.fail())
	{
		PrnHeadings();
		readIt();
		bEndFlag = false;
	}
}
