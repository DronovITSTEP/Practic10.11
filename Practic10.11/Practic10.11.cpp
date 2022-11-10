#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    /*
    Пользователь вводит с клавиатуры две границы
    диапазона и число. Если число не попадает в диапазон,
    программа просит пользователя повторно ввести число,
    и так до тех пор, пока он не введет число правильно. 
    */

    /*int a, b, c;

    cout << "Ввдеите диапазон чисел\n";
    cin >> a >> b;

    do {
        cout << "Введите число: ";
        cin >> c;
        if (c >= min(a, b) && c <= max(a, b)) cout << "Число входит в дапазон\n";
        else cout << "Число не входит в диапазон чисел, повторите попытку\n";
    } while (c <= min(a, b) || c >= max(a, b));*/

    /*
     Написать имитацию кассового аппарата для
    магазина, торгующего новогодними товарами. Кассир
    должен выбрать товар из списка, ввести его количество,
    затем выбрать следующий товар. По завершению ввода
    вывести на экран всю сумму покупки. Предусмотреть
    наличие скидки. В списке товаров должно быть не меньше
    4-х товаров, должна отображаться их цена. Предусмотреть
    неправильно вводимые данные.
        ■ Реализовать возможность обслуживания нескольких
        клиентов подряд;
        ■ Хранение общей выручки магазина;
        ■ Ограничить количество товара в магазине.
    */

    

    // количество товаров в магазине
    int countTree = 10, countToys = 25, countGarland = 7, countBox = 50;

    // цена товара
    int priceTree = 1500, priceToys = 3999, priceGarland = 769, priceBox = 50;

    // общая выручка магазина
    float summa = 0;

    // кол-во выбранного товара клиентом
    int countClient = 0;

    // сумма заказа клиента
    float finalPrice = 0;

    char c; // выбор товара
    char yes_no; // да нет
    int count; // выбор кол-ва товара
    bool flag = true;
    while (flag) {
        cout << "Списко новогодних товаров\n---------------------\n"
            << "1. Елка зеленая (средняя) - 1500р ( " << countTree << " )\n"
            << "2. Игрушки отечественные фарфоровые - 3999р ( " << countToys << " )\n"
            << "3. Гирлядны разноцветные - 769р ( " << countGarland << " )\n"
            << "4. подарочная коробка - 50р ( " << countBox << " )\n\n";

        cout << "Ваш выбор: ";
        cin >> c;

        switch (c)
        {
        case '1':
            while (true)
            {       
                cout << "Введите количство товара: ";
                cin >> count;
                if (count >= countTree || count <= 0)
                    cout << "Введено неверное количство товара. Повторите ввод\n";
                else {
                    finalPrice += count * priceTree;
                    countTree -= count;
                    break;
                }     
            }             
            break;
        case '2':
            while (true)
            {
                cout << "Введите количство товара: ";
                cin >> count;
                if (count >= countToys || count <= 0)
                    cout << "Введено неверное количство товара. Повторите ввод\n";
                else {
                    finalPrice += count * priceToys;
                    countToys -= count;
                    break;
                }
            }
            break;
        case '3':
            while (true)
            {
                cout << "Введите количство товара: ";
                cin >> count;
                if (count >= countGarland || count <= 0)
                    cout << "Введено неверное количство товара. Повторите ввод\n";
                else {
                    finalPrice += count * priceGarland;
                    countGarland -= count;
                    break;
                }
            }
            break;
        case '4':
            while (true)
            {
                cout << "Введите количство товара: ";
                cin >> count;
                if (count >= countBox || count <= 0)
                    cout << "Введено неверное количство товара. Повторите ввод\n";
                else {
                    finalPrice += count * priceBox;
                    countBox -= count;
                    break;
                }
            }
            break;
        default:
            cout << "Введен неверный идентификатор товара\n";
            break;
        }

        cout << "Хотите выбрать еще что-нибудь?(y/n): ";
        cin >> yes_no;
        if (yes_no == 'y') continue;

        if (finalPrice > 5000) finalPrice *= 0.9;

        cout << "Общая стоимость покупки: " << finalPrice << endl;

        cout << "Спасибо за покупку. Приходите еще!:)\n\n";

        summa += finalPrice;

        cout << "Обслужить следующего клиента (y/n): ";
        cin >> yes_no;
        if (yes_no == 'n') {
            cout << "Магазин закончил работу на сегодня\n";
            flag = false;
        }      
    }
    
    cout << "Общая выручка магазина: " << summa << endl;
}
