/*
Завдання: Магазин кави
Уявіть, що ви розробляєте систему для кавового магазину. У вас є класи для представлення 
продуктів (кава, чай, печиво), класи для клієнтів і класи для обробки замовлень. Ваша 
мета - використати поведінкові патерни для полегшення взаємодії між різними елементами системи.
1. Створення продуктів:
• Реалізуйте ієрархію класів для представлення продуктів (кава, чай, печиво).
• Використайте патерн Фабричний метод для створення екземплярів продуктів.
2. Клієнти:
• Розробіть класи для представлення клієнтів. Клієнт може розміщувати замовлення та переглядати свою історію замовлень.
• Використайте патерн Посередник для того, щоб клієнти могли слідкувати за станом своїх замовлень.
3. Замовлення:
• Розробіть клас для представлення замовлення, який включає в себе список продуктів та клієнта, який зробив замовлення.
• Використайте патерн Команда для імплементації замовлення.
4. Знижки та промокоди:
• Реалізуйте можливість застосовувати знижки або промокоди до замовлень.
• Використайте патерн Ланцюжок відповідальностей для обробки різних типів знижок.
5. Сплачено та відправлено:
• Додайте можливість позначати замовлення як сплачені та відправлені.
*/

#include <iostream>
#include <memory>
#include "ProductFactory.h"
#include "Client.h"
#include "Order.h"
#include "Discount.h"

int main()
{
    system("chcp 1251>null");

    auto discount500 = std::make_shared<Discount500>();
    auto discount1000 = std::make_shared<Discount1000>();
    discount500->SetSuccessor(discount1000);

    std::shared_ptr<Client> client1 = std::make_shared<Client>("Хоменко Олександр");
    std::string client1Name = client1->getName();
    std::cout << "Замовник: " << client1Name << std::endl;

    std::unique_ptr<OrderMediator> mediator1 = std::make_unique<OrderTrackingSystem>();
    std::unique_ptr<Order> order1 = std::make_unique<Order>(client1.get(), mediator1.get(), discount500);

    order1->addProduct(std::make_unique<NescafeCoffee>());
    order1->addProduct(std::make_unique<LovareTea>());
    order1->addProduct(std::make_unique<BiscottiCookie>());
    order1->showOrder();

    order1->markAsPaid();
    order1->markAsShipped();

    client1->placeOrder(std::move(order1));

    std::cout << std::endl;
    std::cout << "Замовник: " << client1Name << std::endl;

    std::unique_ptr<OrderMediator> mediator2 = std::make_unique<OrderTrackingSystem>();
    std::unique_ptr<Order> order2 = std::make_unique<Order>(client1.get(), mediator2.get(), discount500);

    order2->addProduct(std::make_unique<FortuneCookie>());
    order2->addProduct(std::make_unique<SherlockTea>());
    order2->addProduct(std::make_unique<QualiteaTea>());
    order2->addProduct(std::make_unique<LavazzaCoffee>());
    order2->showOrder();

    order2->markAsPaid();
    order2->markAsShipped();

    client1->placeOrder(std::move(order2));
    client1->viewOrderHistory();

    std::shared_ptr<Client> client2 = std::make_shared<Client>("Романчук Олена");
    std::string client2Name = client2->getName();
    std::cout << "Замовник: " << client2Name << std::endl;

    std::unique_ptr<OrderMediator> mediator3 = std::make_unique<OrderTrackingSystem>();
    std::unique_ptr<Order> order3 = std::make_unique<Order>(client2.get(), mediator3.get(), discount500);

    order3->addProduct(std::make_unique<DeliciaCookie>());
    order3->addProduct(std::make_unique<AmbassadorCoffee>());
    order3->showOrder();

    order3->markAsPaid();

    client2->placeOrder(std::move(order3));
    client2->viewOrderHistory();

	return 0;
}