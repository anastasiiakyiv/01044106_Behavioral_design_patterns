#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Order.h"

class Client 
{
private:
    std::string name;
    std::vector<std::unique_ptr<Order>> orders;

public:
    Client(const std::string& name) : name(name) {}

    std::string getName() const 
    {
        return name;
    }
    
    void placeOrder(std::unique_ptr<Order> order) 
    {
        if (order->isOrderPaid() && order->isOrderShipped()) 
        {
            orders.push_back(std::move(order));
        }
        else 
        {
            std::cout << "���������� � �������." << std::endl;
        }
    }

    void viewOrderHistory() 
    {
        if (orders.empty()) 
        {
            std::cout << std::endl;
            std::cout << "������� ��������� ������: " << name << std::endl;
            std::cout << "������ ��������� �������" << std::endl;
            return;
        }
        std::cout << std::endl;
        std::cout << "������� ��������� ������: " << name << std::endl;
        std::cout << "������ ���������:" << std::endl;
        std::cout << std::endl;
        for (const auto& order : orders) 
        {
            std::cout << "������:";

            if (order->isOrderPaid()) 
            {
                std::cout << std::endl;
                std::cout << "* ��������";
            }
            else 
            {
                std::cout << std::endl;
                std::cout << "* �� ��������";
            }

            if (order->isOrderShipped()) 
            {
                std::cout << std::endl;
                std::cout << "* ����������" << std::endl;
            }
            else 
            {
                std::cout << std::endl;
                std::cout << "* �� ����������" << std::endl;
            }
            order->showOrder();
        }
    }
};