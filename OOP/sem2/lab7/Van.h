#pragma once
class Van
{
private:
	bool type;
	int number;

public:
	Van(bool, int);
	Van() : Van(0, 0) {}
	bool VanType();
	void VanInfo();
};

