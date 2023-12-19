#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Client.h"
#include "Discount.h"

class Order;
class Client;

class OrderMediator 
{
public:
    virtual void trackOrderStatus(Order* order) = 0;
};

class Order 
{
private:
    std::vector<std::unique_ptr<Product>> products;
    Client* client;
    bool isPaid;
    bool isShipped;
    OrderMediator* mediator;
    std::shared_ptr<Discount> discount;

public:
    Order(Client* client, OrderMediator* mediator, std::shared_ptr<Discount> discount)
        : client(client), isPaid(false), isShipped(false), mediator(mediator), discount(discount) {}

    void addProduct(std::unique_ptr<Product> product) 
    {
        products.push_back(std::move(product));
    }

    void markAsPaid() 
    {
        isPaid = true;
        if (mediator != nullptr) 
        {
            mediator->trackOrderStatus(this);
        }
    }

    void markAsShipped() 
    {
        isShipped = true;
        if (mediator != nullptr) 
        {
            mediator->trackOrderStatus(this);
        }
    }

    bool isOrderPaid() const 
    {
        return isPaid;
    }

    bool isOrderShipped() const 
    {
        return isShipped;
    }

    void showOrder() 
    {
        std::cout << "������ � ������:" << std::endl;
        double totalPrice = 0.0;

        for (const auto& product : products) 
        {
            std::cout << "- " << product->productInfo() << "; ����: " << product->getPrice() << " ���" << std::endl;
            totalPrice += product->getPrice();
        }

        Claim orderAmount(totalPrice);
        double discountedAmount = discount->Process(orderAmount);

        std::cout << "�������� ����: " << totalPrice << " ���" << std::endl;
        std::cout << "���� � �������: " << discountedAmount << " ���" << std::endl;
        std::cout << std::endl;
    }
};

class OrderTrackingSystem : public OrderMediator 
{
public:
    void trackOrderStatus(Order* order) override 
    {
        if (order->isOrderPaid() && order->isOrderShipped()) 
        {
            std::cout << "�������� ������ ����������: �������� �� ����������." << std::endl;
        }
        else if (order->isOrderPaid()) 
        {
            std::cout << "�������� ������ ����������: ��������." << std::endl;
        }
        else if (order->isOrderShipped()) 
        {
            std::cout << "�������� ������ ����������: ����������." << std::endl;
        }
        else 
        {
            std::cout << "�������� ������ ����������: � �������." << std::endl;
        }
    }
};