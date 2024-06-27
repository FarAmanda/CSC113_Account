#pragma once

#include <algorithm>
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

		//for sorting and printing the account objects based on ID
		static bool sortAscID(const account& a, const account& b);
		void printAscID(account arr[], int size);

		//not necessary because we only need to display in ascending order
		//void printDesc(account arr[]);

	// Member Variables
		std::string name;
		int accountNum;
		double balance;
		int accountCount;
		
	private:



	};
}