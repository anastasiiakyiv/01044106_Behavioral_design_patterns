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
		return "���� �������� NESCAFE Gold 400 �";
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
		return "���� � ������ Ambassador Blue Label 1 ��";
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
		return "���� ������ Lavazza Crema&Gusto 250 �";
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
		return "Lovare Winter tea Assorted 4 ���� �� 8 ��";
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
		return "��� ������� ����������� Qualitea 100 ��������";
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
		return "��� ������ Sherlock Secrets �������� 100 �";
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
		return "������ ������-������� Biscotti 500 �";
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
		return "������ Fortune � �������������� 84 � � 16 ��";
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
		return "������ ������ Delicia � ������� 320 �";
	}

	double getPrice() override
	{
		return 99.0;
	}
};