#include "MyForm.h"
#include "Linearstuff.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array < String^ > ^ args) {
	//engage file dialogue
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project2::MyForm form;
	Application::Run(%form);

	//engage file read
	Linearstuff linear;
	linear.initialize();




	return 0;
}


