#include "grafoForm.h"
#include <malloc.h>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;

[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	grafo::grafoForm form;
	Application::Run(%form);
}