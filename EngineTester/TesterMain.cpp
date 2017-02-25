#include <QtCore/QCoreApplication>
#include <gtest\gtest.h>
#include <iostream>

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();


	std::cout << "\nEnter any key to continue . . ." << std::endl;
	char t;
	std::cin >> t;
}
