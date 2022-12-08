#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//Order class
class Order
{
private:
	string menuItems[8];
	int count;
	double subtotal;
public:
	//constructor
	Order()
	{
		count = 0;
		subtotal = 0;
	}
	//addItem function
	void addItem(string item, double price)
	{
		menuItems[count] = item;
		count++;
		subtotal += price;
	}
	void printOrder()
	{
		for (int i = 0; i < count; i++)
		{
			cout << menuItems[i] << endl;
		}
		cout << fixed << setprecision(2);
		cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "\nSubTotal: $" << subtotal << endl;
	}
};

//OrderNode class
class OrderNode
{
public:
	Order order;
	OrderNode *next;
	OrderNode(Order order)
	{
		this->order = order;
		next = nullptr;
	}
};

//OrderQueue class
class OrderQueue
{
private:
	OrderNode *rear, *front;
public:
	//constructor
	OrderQueue()
	{
		rear = front = nullptr;
	}
	//enqueue function
	void enqueue(Order order)
	{
		OrderNode *node = new OrderNode(order);
		if (rear == nullptr)
		{
			rear = front = node;
			return;
		}
		rear->next = node;
		rear = rear->next;
	}
	//dequeue function
	Order dequeue()
	{
		if (front == nullptr)
			throw "Queue is empty";
		Order order = front->order;
		front = front->next;
		if (front == nullptr)
			rear = nullptr;
		return order;
	}
	//traverse function
	void traverse()
	{
		OrderNode *temp = front;
		int i = 1;
		while (temp != nullptr)
		{
			cout << "\nOrder " << i << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			temp->order.printOrder();
			temp = temp->next;
			i++;
		}
	}

};

//main function
int main()
{
	OrderQueue q;
	int op;

	while (1)
	{
		cout << "Jester's Diner Menu" << endl;
		cout << "1. Take an Order\n2. Close out an Order\n3. List all pending Orders\n4. Go home" << endl;

		cin >> op;

		switch (op)
		{
			//Take an Order
		case 1:
		{

			Order order;
			int i = 0;
			string items[4] = { "Coffee", "Tea", "Soft Drink ", "Water" };
			double price[] = { 2.99, 2.59, 1.49, 0.99 };
			while (1)
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "1. Coffee -     $2.99" << endl;
				cout << "2. Tea -        $2.59" << endl;
				cout << "3. Soft Drink - $1.49" << endl;
				cout << "4. Water -      $0.99" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "5.<Look at Appitizers>" << endl;
				cout << "6.<Look at Entrees>" << endl;
				cout << "7.<Look at Desserts>" << endl;
				cout << "8. <No More Items>" << endl;

				cin >> op;

				if (op == 8) break;
				if (op >= 1 && op <= 4)
				{
					order.addItem(items[op - 1], price[op - 1]);
					q.enqueue(order);
				}
				cout << items[op - 1] << " added to the order." << endl;
				i++;
				if (i == 8) break;
			}
		
		}

		case 2:
		{

			Order order;
			int i = 0;
			string items[4] = { "Chesse Sticks", "Chicken Wings", "Blooming Onion ", "Sliders" };
			double price[] = { 7.99, 8.50, 6.99, 9.99 };
			while (1)
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "1. Chesse Sticks -     $7.99" << endl;
				cout << "2. Chicken Wings -     $8.50" << endl;
				cout << "3. Blooming Onion -	$6.99" << endl;
				cout << "4. Sliders -			$9.99" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "5.<Look at Drinks>" << endl;
				cout << "6.<Look at Entrees>" << endl;
				cout << "7.<Look at Desserts>" << endl;
				cout << "8. <No More Items>" << endl;

				cin >> op;

				if (op == 8) break;
				if (op >= 1 && op <= 4)
				{
					order.addItem(items[op - 1], price[op - 1]);
					q.enqueue(order);
				}
				if (op >= 5 && op<= 7)break;
				cout << items[op - 1] << " added to the order." << endl;
				i++;
				if (i == 8) break;
			}

		}
		case 3:
		{

			Order order;
			int i = 0;
			string items[4] = { "Burger & Fries", "Pepperoni Pizza", "Pepperoni Pizza ", "Seafood Platter" };
			double price[] = { 8.99, 8.50, 12.99, 15.99 };
			while (1)
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "1. Burger & Fries -	$8.99" << endl;
				cout << "2. Pepperoni Pizza -	$8.50" << endl;
				cout << "3. Steak -				$12.99" << endl;
				cout << "4. Seafood Platter -	$15.99" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "5.<Look at Drinks>" << endl;
				cout << "6.<Look at Appitizers>" << endl;
				cout << "7.<Look at Desserts>" << endl;
				cout << "8. <No More Items>" << endl;

				cin >> op;

				if (op == 8) break;
				if (op >= 1 && op <= 4)
				{
					order.addItem(items[op - 1], price[op - 1]);
					q.enqueue(order);
				}
				if (op >= 5 && op <= 7)break;
				cout << items[op - 1] << " added to the order." << endl;
				i++;
				if (i == 8) break;
			}

		}
		case 4:
		{

			Order order;
			int i = 0;
			string items[3] = { "Pie", "Clocolate Cake", "Shakes " };
			double price[] = { 5.99, 9.50, 4.99 };
			while (1)
			{
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "1. Pie -				$5.99" << endl;
				cout << "2. Clocolate Cake -	$9.50" << endl;
				cout << "3. Shakes -			$4.99" << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "5.<Look at Drinks>" << endl;
				cout << "6.<Look at Appitizers>" << endl;
				cout << "7.<Look at Entrees>" << endl;
				cout << "8. <No More Items>" << endl;

				cin >> op;

				if (op == 8) break;
				if (op >= 1 && op <= 3)
				{
					order.addItem(items[op - 1], price[op - 1]);
					q.enqueue(order);
				}
				if (op >= 5 && op <= 7)break;
				cout << items[op - 1] << " added to the order." << endl;
				i++;
				if (i == 8) break;
			}

		}

		break;

		//Close an Order
		case 5:
		{
			Order order = q.dequeue();
			cout << "\n*** Closed Order ***" << endl;
			order.printOrder();
		}

		break;

		//Review all Orders
		case 6:
			q.traverse();

			break;
			//Exit
		case 7:
			return 0;
		}
		cout << endl;
	}
}