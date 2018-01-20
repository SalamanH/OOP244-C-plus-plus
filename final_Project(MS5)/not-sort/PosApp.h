#ifndef _244_POSAPP_H_
#define _244_POSAPP_H_
#include "Item.h"
namespace ict{
	class PosApp{
	private:
		char m_filename[128];
		char m_billfname[128];
		Item* m_items[MAX_NO_ITEMS];
		int m_noOfItems;
		int menu();
		void deallocateItems();
		void loadRecs();
		void saveRecs();
		int searchItems(const char* sku)const;
		void updateQty();
		void addItem(bool isPerishable);
		void listItems()const;
		void truncateBillFile();
		void showBill();
		void addToBill(Item& I);
		void POS();
		void sort();
		int sort_menu();
		void sort_sku(bool asc);
		void sort_item_name(bool asc);
		void sort_price(bool asc);
		void sort_quantity(bool asc);

		//std::fstream dfile;

	public:
		PosApp(const char* filename, const char* billfname);
		PosApp(PosApp&) = delete;
		void run();
		


	};

};








#endif