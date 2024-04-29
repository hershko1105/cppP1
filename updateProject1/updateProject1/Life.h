
#define Start_Life 3

class life
{
private:
	unsigned int _beginnersLife = Start_Life;
	unsigned int _currLife;


public:
	unsigned int getCurrLife() {
		return _currLife;
	}
	unsigned int getBegginnersLife() {
		return _beginnersLife;
	}
	void setCurrlife(unsigned int newCurrLife) {
		_currLife = newCurrLife;
	}
	void reSetLife() {
		_currLife = _beginnersLife;
	}


}; 

