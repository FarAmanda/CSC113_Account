#pragma once
#include <string>


namespace banking {
	class account {
	public:
		account() {
			name = "";
			accountNum = 0;
			balance = 0.0;
			accountCount = 0;
		}
	// Member Functions
		double credit();
		double debit();
		int startUp(account accounts[], int size);
		void printAsc(account arr[]);
		void printDesc(account arr[]);

	// Member Variables
		std::string name;
		int accountNum;
		double balance;
		int accountCount;
		
	private:



	};
}