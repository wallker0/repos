#include "MyForm.h"
#include <Windows.h>
using namespace Project1; // Change this to your project name

int Main()
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	// Create the main window and run it
	Application::Run(gcnew MyForm()); //Form1 is the name of the form created. 
	return 0;
}