#pragma once
#define STAY 1
#define MOVE 0
class Ship
{
private:
	int _x;
	int _y;
	int _width;
	int _height;
	int _motion; //STAY - 1 MOVE - 0
public:
	//todo - move code to .cpp file
	void init(int x, int y, int width, int height, int motion/*,Ship* this*/) {
		_x = x;
		_y = y;
		_width = width;
		_height = height;
		_motion = motion;
	}
	//todo - more getters and setters - wherever needed - DONE
	int getX() {
		return _x;
	}
	int getY() {
		return _y;
	}
	int getWidth() {
		return _width;
	}
	int getHeight() {
		return _height;
	}
	int getMotion() {
		return _motion;
	}
	void setX(int x) {
		_x = x;
	}
	void setY(int y) {
		_y = y;
	}
	void setWidth(int width) {
		_width = width;
	}
	void setHeight(int height) {
		_height = height;
	}
	void setMotion(int motion) {
		_motion = motion;
	}

}; 

