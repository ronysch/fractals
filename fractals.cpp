// fractals.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

using namespace fractals;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	//צריך לכתוב מחלקה שמכילה את הזום מיקם וכו' כ
	Application::Run(gcnew Form1());
	return 0;
}
