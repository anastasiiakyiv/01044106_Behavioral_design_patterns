#pragma once
#include<iostream>
#include<string>

class Product
{
public:
	virtual std::string productInfo() = 0;
	virtual double getPrice() = 0;
	virtual ~Product() {};
};

class Coffee : public Product 
{
	std::string productInfo() override
	{
		return "";
	}

	double getPrice() override
	{
		return 0.0;
	}
};

class Tea : public Product
{
	std::string productInfo() override
	{
		return "";
	}

	double getPrice() override
	{
		return 0.0;
	}
};

class Cookie : public Product
{
	std::string productInfo() override
	{
		return "";
	}

	double getPrice() override
	{
		return 0.0;
	}
};

class NescafeCoffee : public Coffee
{
public:
	std::string productInfo() override
	{
		return "Кава розчинна NESCAFE Gold 400 г";
	}

	double getPrice() override
	{
		return 389.0;
	}
};

class AmbassadorCoffee : public Coffee
{
public:
	std::string productInfo() override
	{
		return "Кава в зернах Ambassador Blue Label 1 кг";
	}

	double getPrice() override
	{
		return 399.0;
	}
};

class LavazzaCoffee : public Coffee
{
public:
	std::string productInfo() override
	{
		return "Кава мелена Lavazza Crema&Gusto 250 г";
	}

	double getPrice() override
	{
		return 229.0;
	}
};

class LovareTea : public Tea
{
public:
	std::string productInfo() override
	{
		return "Lovare Winter tea Assorted 4 види по 8 шт";
	}

	double getPrice() override
	{
		return 65.0;
	}
};

class QualiteaTea : public Tea
{
public:
	std::string productInfo() override
	{
		return "Чай зелений пакетований Qualitea 100 пакетиків";
	}

	double getPrice() override
	{
		return 139.0;
	}
};

class SherlockTea : public Tea
{
public:
	std::string productInfo() override
	{
		return "Чай чорний Sherlock Secrets листовий 100 г";
	}

	double getPrice() override
	{
		return 97.0;
	}
};

class BiscottiCookie : public Cookie
{
public:
	std::string productInfo() override
	{
		return "Печиво пісочно-відсадне Biscotti 500 г";
	}

	double getPrice() override
	{
		return 87.0;
	}
};

class FortuneCookie : public Cookie
{
public:
	std::string productInfo() override
	{
		return "Печиво Fortune з передбаченнями 84 г х 16 шт";
	}

	double getPrice() override
	{
		return 1119.0;
	}
};

class DeliciaCookie : public Cookie
{
public:
	std::string productInfo() override
	{
		return "Здобне печиво Delicia з декором 320 г";
	}

	double getPrice() override
	{
		return 99.0;
	}
};