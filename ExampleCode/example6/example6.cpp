#include <iostream>

using namespace std;

class Clock {
	public:
		Clock() {
			minute = 0;
		};

		Clock(int min) {
			if (!setMinute(min)){
				minute=0;
			}
		};

		bool setMinute(int min) {
			if (min >= 0 && min < 60){
				minute = min;
				return true;
			}else{
				return false;
			}
		};

		int getMinute() const {
			return minute;
		};

		private:
			int minute;
};

int main(void){
	Clock bigBen;
	Clock cooCoo(4);

	bigBen.setMinute(-3);
	bigBen.setMinute(60);
	bigBen.setMinute(23);

	cout << bigBen.getMinute();
}