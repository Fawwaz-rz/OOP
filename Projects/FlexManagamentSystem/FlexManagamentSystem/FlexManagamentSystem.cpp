
#include "Human.h"

int  main()
{

	Human* obj = nullptr;

		obj = sign_in();
		obj->getData();
		obj->displayMenu();

	if (obj)
		delete obj;

	return 0;
}
