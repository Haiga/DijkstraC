#include <stdio.h>
#include <stdlib.h>
using namespace std;

namespace validator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	
	System::Boolean validFloat(System::String ^stringAvaliada) {
		Regex ^ pattern = gcnew Regex("^[-+]?[0-9]*\.?[0-9]+$");
		try
		{
			float::Parse(stringAvaliada);
		}
		catch (OverflowException ^er1)
		{
			return false;
		}
		catch (FormatException ^er2) {
			return false;
		}
		catch (Exception ^er3) {
			return false;
		}
		if (pattern->IsMatch(stringAvaliada) & !stringAvaliada->Contains(".")) {
			if (float::Parse(stringAvaliada) >= 0) {
				return true;
			}
		}
		return false;
	}

	System::Boolean validInteger(System::String ^stringAvaliada) {
		Regex ^ pattern = gcnew Regex("^[0-9]*$");
		try
		{
			int::Parse(stringAvaliada);
		}
		catch (OverflowException ^er1)
		{
			return false;
		}
		catch (FormatException ^er2) {
			return false;
		}
		catch (Exception ^er3) {
			return false;
		}
		if (pattern->IsMatch(stringAvaliada)) {
			if (int::Parse(stringAvaliada) != 0) {
				return true;
			}
		}
		return false;
	}
	
}
