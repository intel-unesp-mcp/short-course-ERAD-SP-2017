#include <iostream>
#include <sstream>
//#include <omp.h>


using namespace std;

void sum(char* output, const long unsigned int d, const long unsigned int n) {
	long unsigned int digits[d + 11];

	for (long unsigned int digit = 0; digit < d + 11; ++digit) {
		digits[digit] = 0;
	}
string filename;

long unsigned int i = 1;
    #pragma omp parallel for
	for (i = 1; i <= n; ++i) {
        //filename=itoa(i);
		//std::ofstream out(filename);
	    //std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
	    //std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

        //int tid = omp_get_thread_num();
		//long unsigned int div[d + 11];
		long unsigned int digitslocal[d + 11];
        for (long unsigned int digit = 0; digit < d + 11; ++digit) {
			digitslocal[digit] = 0;
		}
		long unsigned int remainder = 1;
		int contlocal=0;

		for (long unsigned int digit = 0; digit < d + 11 && remainder; ++digit) {
			long unsigned int div = remainder / i;
          //  div[digit] = remainder / i;
			long unsigned int mod = remainder % i;
			 
			digitslocal[digit] += div;
            //digits[digit] += div[digit];  
			remainder = mod * 10;
            //cout << "thread id " <<  tid << " i " << i << " digits " << digits[digit] << endl;
			contlocal++;
		}
		#pragma omp critical
		{
        	for (int auxcontlocal = 0; auxcontlocal > contlocal; auxcontlocal++) {
				digits[auxcontlocal] += digitslocal[auxcontlocal];
			}
		}

	}

	for (long unsigned int i = d + 11 - 1; i > 0; --i) {
		digits[i - 1] += digits[i] / 10;
		digits[i] %= 10;
	}
	if (digits[d + 1] >= 5) {
		++digits[d];
	}
	for (long unsigned int i = d; i > 0; --i) {
		digits[i - 1] += digits[i] / 10;
		digits[i] %= 10;
	}
	stringstream stringstreamA;
	stringstreamA << digits[0] << ".";
	for (long unsigned int i = 1; i <= d; ++i) {
		stringstreamA << digits[i];
	}
	stringstreamA << '\0';
	string stringA = stringstreamA.str();
	stringA.copy(output, stringA.size());
}

int main() {

	long unsigned int d, n;

	cin >> d >> n;

	char output[d + 10]; // extra precision due to possible error

	sum(output, d, n);

	cout << output << endl;

	return 0;
}
