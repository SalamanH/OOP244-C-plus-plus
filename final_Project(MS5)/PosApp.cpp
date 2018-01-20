#define _CRT_SECURE_NO_WARNINGS
// Lib includesostream
#include <iostream>
#include <cstring>
// inlcude Item and POS header files
#include "PosApp.h"
#include "Perishable.h"
using namespace std;
namespace ict{

	int PosApp::menu(){
		int selection;
		cout << "The Sene-Store" << endl
			<< "1- List items" << endl
			<< "2- Add Perishable item" << endl
			<< "3- Add Non-Perishable item" << endl
			<< "4- Update item quantity" << endl
			<< "5- Show Item" << endl
			<< "6- POS" << endl
			<< "7- Sort" << endl
			<< "0- exit program" << endl
			<< "> ";
		//cin.ignore(2000, '\n');
		cin >> selection;

        if (selection < 8 && selection >= 0)
            cin.ignore(1);
		else{
			selection = -1;
			//cin.ignore(INT_MAX);
			cin.ignore('\n');
		}
			

		return selection;
	}
	void PosApp::deallocateItems(){

		for (int i = 0; i < m_noOfItems; i++) {
			delete m_items[i];
		}
		m_noOfItems = 0;
	}
    void PosApp::loadRecs() {
        int index = 0;
        deallocateItems();
        fstream dfile(m_filename, ios::in);
        if (dfile.fail()) {
            dfile.clear();
            dfile.close();
            fstream dfile(m_filename, ios::out);
            dfile.close();
        }
        else {
			while(!dfile.eof()){
				char signiture;
				signiture = dfile.get();
				
				if (signiture == 'P') {
					m_items[index] = new Perishable;
				}
				else {
					//NonPerishable* n_item = new Item* m_items[index];
					m_items[index] = new NonPerishable;
				}
				if (signiture == 'P' || signiture == 'N') {
                    dfile.ignore();
					m_items[index]->load(dfile);
					index++;
				}
				
			}
			m_noOfItems = index;
            dfile.close();
        }
    
	}
	void PosApp::saveRecs(){
        fstream dfile(m_filename, ios::out);
        for (int i = 0; i < m_noOfItems; i++) {
			if (m_items[i]->quantity() > 0){
                m_items[i]->save(dfile);
				
			}
			dfile << endl;
        }
        dfile.close();
        loadRecs();
	}
	int PosApp::searchItems(const char* sku)const{
		int result = -1;
		
		for (int i = 0; i < m_noOfItems; i++){
			if (strcmp(m_items[i]->sku(),sku) == 0)
				result = i;
		}
		return result;
	}
	void PosApp::updateQty(){    // check this 
		char sku_temp[MAX_SKU_LEN] = "";
		int sku_index;
		int num_items;
		cout << "Please enter the SKU: ";
		cin >> sku_temp;
		sku_index = searchItems(sku_temp);
		if (sku_index == -1)
			cout << "Not Found!" << endl;
		else{
			m_items[sku_index]->write(cout, false);
			cout << endl << "Please enter the number of purchased items: ";
			cin >> num_items;
			*m_items[sku_index] += num_items;

			saveRecs();
			cout << "Updated!" << endl;
		}
	}
	void PosApp::addItem(bool isPerishable){
        std::fstream dfile(m_filename, ios::out);
		Item* item_temp;
		std::cout << endl;
		if (isPerishable)
		    item_temp = new Perishable();
		else
			item_temp = new NonPerishable();
		cin >> *item_temp;
		if (cin.fail()){
				cin.clear();
				cout << *item_temp;
		}
		else{
				
			/*for (int i = 0; i < m_noOfItems; i++){
				m_items[i]->save(dfile);
				dfile << endl;
			}
			item_temp->save(dfile);
			loadRecs();
			dfile << endl;*/
			m_items[m_noOfItems] = item_temp;
			m_noOfItems++;
			this->saveRecs();
			
			loadRecs();
			cout << "Item added." << endl << endl;
		}
		
	dfile.close();
	}
	void PosApp::listItems()const{
		double total = 0;
		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl
		     << "-----|--------|--------------------|-------|---|----|---------|" << endl;
		for (int i = 0; i < m_noOfItems; i++){
			cout.width(4);
			cout << (i + 1) << " | " << *m_items[i] << endl;
			total += *m_items[i];

		}
		cout << "-----^--------^--------------------^-------^---^----^---------^" << endl
			<< "                               Total Asset: $  |       ";
		cout.width(7); 
		cout << total << "|" << endl
			<< "-----------------------------------------------^--------------^" << endl;
	}
	void PosApp::truncateBillFile(){
        fstream dfile(m_billfname, ios::out | ios::trunc);

		dfile.close();
	}
	void PosApp::showBill(){
		double total = 0;
		
        std::fstream dfile(m_billfname, ios::in);
		cout << "v--------------------------------------------------------v" << endl
			 << "| 2017/04/02, 12:42                                      |" << endl
			 << "| SKU    | Item Name          | Price |TX |Qty |   Total |" << endl
			 << "|--------|--------------------|-------|---|----|---------|" << endl;

		while(!dfile.eof()){
			Item* item_temp;
			char signiture_temp = dfile.get();
			if (signiture_temp == 'P')
				item_temp = new Perishable;
			else
				item_temp = new NonPerishable;
            if (signiture_temp == 'P' || signiture_temp == 'N') {
                dfile.ignore();
                item_temp->load(dfile);
                cout << "| ";
                item_temp->write(cout, true);
                cout << endl;
                total += item_temp->price() * item_temp->quantity() * ((item_temp->taxed()) ? (1 + TAX) : 1);
                delete item_temp;
            }
		}
		cout << "^--------^--------------------^-------^---^----^---------^" << endl
			 << "|                               Total: $  |"; cout.width(14);
		cout << total << "|" << endl
			 << "^-----------------------------------------^--------------^" << endl;
		
        dfile.close();
		
        truncateBillFile();
	}
	void PosApp::addToBill(Item& I){
        std::fstream dfile(m_billfname, ios::out | ios::app);
		int quantity_temp = I.quantity();
		I.quantity(1);
		I.save(dfile);
		I.quantity(quantity_temp - 1);
        dfile << endl;
		dfile.close();
		saveRecs();

	}
	void PosApp::POS(){
		bool stop_temp = false;
		char sku_temp[MAX_SKU_LEN];
		while (stop_temp != true){
			cout << "Sku: ";
            cin.getline(sku_temp, MAX_SKU_LEN);
			if (strlen(sku_temp) == 0){
				stop_temp = true;
				showBill();
			}
			else{
				int index_temp = searchItems(sku_temp);
				if (index_temp != -1){
					cout << "v------------------->" << endl;
					cout << "| " << m_items[index_temp]->name() << endl;
					cout << "^------------------->" << endl;

					addToBill(*m_items[index_temp]);
				}
				else
					cout << "Not found!" << endl;
			}
		}
	}

	PosApp::PosApp(const char* filename, const char* billfname){
		strcpy(m_billfname, billfname);
		strcpy(m_filename, filename);
		m_noOfItems = 0;
		loadRecs();
	}
	int PosApp::sort_menu(){
		int sort_select;
		cout << "Sort on:" << endl
			<< "1- Sku" << endl
			<< "2- Item Name" << endl
			<< "3- Price" << endl
			<< "4- Quantity" << endl
			<< "0- exit Sort" << endl
			<< "> ";
		cin >> sort_select;
		if (sort_select < 5 && sort_select >= 0)
			sort_select = sort_select;
		else
			sort_select = -1;
		return sort_select;
	}
	void PosApp::sort(){
		bool leave = false;
		int sort_select;
		char asc;
		bool asc_b;
		
		while (leave == false) {
			asc_b = false;
			sort_select = sort_menu();
			switch (sort_select)
			{
			case 1:
				cout << "Ascending? (y/n) ";
				cin >> asc;
				if (asc == 'y')
					asc_b = true;

				sort_sku(asc_b);
				listItems();
				break;
			case 2:
				cout << "Ascending? (y/n) ";
				cin >> asc;
				if (asc == 'y')
					asc_b = true;

				sort_item_name(asc_b);
				listItems();
				break;
			case 3:
				cout << "Ascending? (y/n) ";
				cin >> asc;
				if (asc == 'y')
					asc_b = true;

				sort_price(asc_b);
				listItems();
				break;
			case 4:
				cout << "Ascending? (y/n) ";
				cin >> asc;
				if (asc == 'y')
					asc_b = true;

				sort_quantity(asc_b);
				listItems();
				break;
			case 0:
				cout << "Aborted!" << endl << endl;
				leave = true;
				break;
			default:
				cout << "===Invalid Selection, try again===" << endl;
				//cin.ignore(2000,'\n');
				std::cin.clear();
				break;
			}
		}
	}
	void PosApp::sort_sku(bool asc){
		Item* temp[MAX_NO_ITEMS];
		temp[0] = m_items[m_noOfItems - 1];
		for (int i = 0; i < m_noOfItems; i++) 
		{


			for (int j = 0; j < m_noOfItems - 1; j++) 
			{
				if (!asc)
					if (strcmp(m_items[j]->sku(), m_items[j + 1]->sku()) < 0)
					{
						
						temp[j] = m_items[j];
						m_items[j] = m_items[j + 1];
						m_items[j + 1] = temp[j];

					}
				
					if (asc)
					if (strcmp(m_items[j]->sku(), m_items[j + 1]->sku()) > 0)
					{

						temp[j] = m_items[j];
						m_items[j] = m_items[j + 1];
						m_items[j + 1] = temp[j];
					}
				//cout << endl << "i = " << i << " : " << "j = " << j << " : " << m_items[j]->sku() << " : " << m_items[j + 1]->sku() << "     ";
				/*for (int x = 0; x<m_noOfItems; x++)
					cout << " " << m_items[x]->sku();*/
			}
			


		}

		saveRecs();
		
	}
	void PosApp::sort_item_name(bool asc){

		Item* temp[MAX_NO_ITEMS];
		temp[0] = m_items[m_noOfItems - 1];
		for (int i = 0; i < m_noOfItems; i++)
		{


			for (int j = 0; j < m_noOfItems - 1; j++)
			{
				if (!asc)
				if (strcmp(m_items[j]->name(), m_items[j + 1]->name()) < 0)
				{

					temp[j] = m_items[j];
					m_items[j] = m_items[j + 1];
					m_items[j + 1] = temp[j];

				}

				if (asc)
				if (strcmp(m_items[j]->name(), m_items[j + 1]->name()) > 0)
				{

					temp[j] = m_items[j];
					m_items[j] = m_items[j + 1];
					m_items[j + 1] = temp[j];
				}
				//cout << endl << "i = " << i << " : " << "j = " << j << " : " << m_items[j]->sku() << " : " << m_items[j + 1]->sku() << "     ";
				/*for (int x = 0; x<m_noOfItems; x++)
				cout << " " << m_items[x]->sku();*/
			}



		}

		saveRecs();
		

	}
	void PosApp::sort_price(bool asc){
		Item* temp[MAX_NO_ITEMS];
		for (int i = 1; i<m_noOfItems; i++)
		{
			for (int j = 0; j<(m_noOfItems - i); j++)
			{

				if (asc)
				if (m_items[j]->price()>m_items[j + 1]->price())
				{
					temp[j] = m_items[j];
					m_items[j] = m_items[j + 1];
					m_items[j + 1] = temp[j];
				}
				if (!asc)
				if (m_items[j]->price() < m_items[j + 1]->price())
				{
					temp[j] = m_items[j];
					m_items[j] = m_items[j + 1];
					m_items[j + 1] = temp[j];
				}
			}


		}
		saveRecs();
		
	}
	void PosApp::sort_quantity(bool asc){
		Item* temp[MAX_NO_ITEMS];
		for (int i = 1; i<m_noOfItems; i++)
		{
			for (int j = 0; j<(m_noOfItems - i); j++)
			{

				if (asc)
				if (m_items[j]->quantity()>m_items[j + 1]->quantity())
				{
					temp[j] = m_items[j];
					m_items[j] = m_items[j + 1];
					m_items[j + 1] = temp[j];
				}
				if (!asc)
				if (m_items[j]->quantity() < m_items[j + 1]->quantity())
				{
					temp[j] = m_items[j];
					m_items[j] = m_items[j + 1];
					m_items[j + 1] = temp[j];
				}
			}


		}
		saveRecs();
		
	}
	void PosApp::run(){
		int selection;
		
		bool leave = false;
		char sku_temp[MAX_SKU_LEN] = "";
        int index_temp;
		while (leave == false) {
			//cin.ignore(1);
			//selection = 10;
			selection = menu();
			//cin.ignore(2000, '\n');
			switch (selection) {
			case 1:
				cout << endl;
				listItems();
				cout << endl;
				break;
			case 2:
				addItem(true);
				break;
			case 3:
				addItem(false);
				break;
			case 4:
				cout << endl;
				updateQty();
				cout << endl;
				break;
			case 5:
				
				cout << endl << "Please enter the SKU: ";
				cin >> sku_temp;
				index_temp = searchItems(sku_temp);

				if (index_temp != -1){
					cout << "v-----------------------------------v" << endl;
					//cout << *m_items[index_temp] << endl;
					m_items[index_temp]->write(cout, false);
					cout << "^-----------------------------------^" << endl;
				}
				else
					cout << "Not found!" << endl;
				cout << endl;
				break;
			case 6:
				cout << endl;
				POS();
				cout << endl;
				break;
			case 7:
				cout << endl;
				sort();
				cout << endl;
				break;
			case 0:
				cout << endl << "Goodbye!" << endl;
				leave = true;
				break;
			default:
				cout << "===Invalid Selection, try again===" << endl;
				//cin.ignore(2000,'\n');
				std::cin.clear();

				break;
			}
		}
	}
}

/*

ouputs:
-------------------------------------
update:
Please enter the SKU: 1313
Name:
Paper Tissue
Sku: 1313
Price: 1.22
Price after tax: 1.38
Quantity: 194
Total Cost: 267.45
Please enter the number of purchased items: 12
Updated!
------------------------------
Please enter the SKU: 3434
Not found!
-------------------------------------
add item:
Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 1200/10/12
Invalid Year in Date Entry
Perishable Item Entry:
Sku: 5656
Name:
Honey
Price: 12.99
Taxed: y
Quantity: 12
Expiry date (YYYY/MM/DD): 2017/5/15
Item Added.
--------------------------------------------
list item:
Row | SKU    | Item Name          | Price |TX |Qty |   Total |
-----|--------|--------------------|-------|---|----|---------|
1 | 1234   |Milk                |   3.99|  P|   2|     7.98|
2 | 3456   |Paper Cups          |   5.99| TN|  38|   257.21|
3 | 4567   |Butter              |   4.56| TP|   9|    46.38|
4 | 1212   |Salted Butter       |   5.99|  P| 111|   664.89|
5 | 1313   |Paper Tissue        |   1.22| TN| 206|   283.99|
6 | 5656   |Honey               |  12.99| TP|  12|   176.14|
-----^--------^--------------------^-------^---^----^---------^
Total Asset: $  |       1436.59|
-----------------------------------------------^--------------^
--------------------------------------
printbill:
v--------------------------------------------------------v
| 2017/04/02, 12:42                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         22.05|
^-----------------------------------------^--------------^
-------------------------------------------------------
POS:
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1212
v------------------->
| Salted Butter
^------------------->
Sku: 1313
v------------------->
| Paper Tissue
^------------------->
Sku: 1234
v------------------->
| Milk
^------------------->
Sku: 7654
Not found!
Sku: 5656
v------------------->
| Honey
^------------------->
Sku:
v--------------------------------------------------------v
| 2017/04/02, 12:58                                      |
| SKU    | Item Name          | Price |TX |Qty |   Total |
|--------|--------------------|-------|---|----|---------|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1212   |Salted Butter       |   5.99|  P|   1|     5.99|
| 1313   |Paper Tissue        |   1.22| TN|   1|     1.38|
| 1234   |Milk                |   3.99|  P|   1|     3.99|
| 5656   |Honey               |  12.99| TP|   1|    14.68|
^--------^--------------------^-------^---^----^---------^
|                               Total: $  |         32.03|
^-----------------------------------------^--------------^
------------------------------------------------------
run:
The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5
Please enter the SKU: 5656
v-----------------------------------v
Name:
Honey
Sku: 5656
Price: 12.99
Price after tax: 14.68
Quantity: 10
Total Cost: 146.79
Expiry date: 2017/05/15
^-----------------------------------^
The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 5
Please enter the SKU: 12345
Not found!
The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> five
===Invalid Selection, try again===
The Sene-Store
1- List items
2- Add Perishable item
3- Add Non-Perishable item
4- Update item quantity
5- Show Item
6- POS
0- exit program
> 0
Goodbye!
*/