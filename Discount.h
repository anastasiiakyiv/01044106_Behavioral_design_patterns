#pragma once
#include <memory>

class Claim 
{
private:
	double amount;

public:
	Claim(double amount = 0.0) : amount(amount) {}

	double GetAmount() const 
	{
		return amount;
	}
	~Claim() {}
};

class Discount 
{
protected:
	std::shared_ptr<Discount> pSuccessor;

public:
	void SetSuccessor(std::shared_ptr<Discount> pTemp) 
	{
		pSuccessor = pTemp;
	}
	virtual double Process(const Claim& amount) = 0;
	virtual ~Discount() {}
};

class Discount500 : public Discount 
{
public:
	Discount500() {}
	~Discount500() {}

	double Process(const Claim& amount) override 
	{
		if (amount.GetAmount() >= 500 && amount.GetAmount() < 1000) 
		{
			return amount.GetAmount() * 0.95;
		}
		else 
		{
			if (pSuccessor) 
			{
				return pSuccessor->Process(amount);
			}
		}
		return amount.GetAmount();
	}
};

class Discount1000 : public Discount 
{
public:
	Discount1000() {}
	~Discount1000() {}

	double Process(const Claim& amount) override 
	{
		if (amount.GetAmount() >= 1000) 
		{
			return amount.GetAmount() * 0.90;
		}
		return amount.GetAmount();
	}
};