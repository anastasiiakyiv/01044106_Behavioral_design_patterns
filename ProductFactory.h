#pragma once
#include <memory>
#include "Product.h"

class ProductFactory
{
public:
    virtual std::unique_ptr<Product> createProduct() = 0;
    virtual ~ProductFactory() {};
};

class CoffeeFactory : public ProductFactory
{
public:
    std::unique_ptr<Product> createProduct() override
    {
        return std::make_unique<Coffee>();
    }
};

class TeaFactory : public ProductFactory
{
public:
    std::unique_ptr<Product> createProduct() override
    {
        return std::make_unique<Tea>();
    }
};

class CookieFactory : public ProductFactory
{
public:
    std::unique_ptr<Product> createProduct() override
    {
        return std::make_unique<Cookie>();
    }
};

class NescafeCoffeeFactory : public CoffeeFactory
{
public:
    std::unique_ptr<Product> createProduct() override 
    {
        return std::make_unique<NescafeCoffee>();
    }
};

class AmbassadorCoffeeFactory : public CoffeeFactory
{
public:
    std::unique_ptr<Product> createProduct() override 
    {
        return std::make_unique<AmbassadorCoffee>();
    }
};

class LavazzaCoffeeFactory : public CoffeeFactory
{
public:
    std::unique_ptr<Product> createProduct() override 
    {
        return std::make_unique<LavazzaCoffee>();
    }
};

class LovareTeaFactory : public TeaFactory
{
public:
    std::unique_ptr<Product> createProduct() override 
    {
        return std::make_unique<LovareTea>();
    }
};

class QualiteaTeaFactory : public TeaFactory
{
public:
    std::unique_ptr<Product> createProduct() override 
    {
        return std::make_unique<QualiteaTea>();
    }
};

class SherlockTeaFactory : public TeaFactory
{
public:
    std::unique_ptr<Product> createProduct() override 
    {
        return std::make_unique<SherlockTea>();
    }
};

class BiscottiCookieFactory : public CookieFactory
{
public:
    std::unique_ptr<Product> createProduct() override 
    {
        return std::make_unique<BiscottiCookie>();
    }
};

class FortuneCookieFactory : public CookieFactory
{
public:
    std::unique_ptr<Product> createProduct() override 
    {
        return std::make_unique<FortuneCookie>();
    }
};

class DeliciaCookieFactory : public CookieFactory
{
public:
    std::unique_ptr<Product> createProduct() override 
    {
        return std::make_unique<DeliciaCookie>();
    }
};