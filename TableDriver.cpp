//https://github.com/Jrwilliams43/Lab-14
#include "TableSortedList.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;
#include "Text.h"
using CSC2110::String;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }
   delete iter;
}

int main()
{
   ListArray<CD>* cds = CD::readCDs("cds.txt");
   int num_items = cds->size();
   cout << num_items << endl;
   CD* last_cd;
   TableSortedList<CD>* slt = new TableSortedList<CD>(&CD::compare_items, &CD::compare_keys);
   ListArrayIterator<CD>* iter = cds->iterator();
   //DO THIS
   //thoroughly test your table
	while(iter->hasNext())
   {
	 CD* cd = iter->next();
	 //cd->displayCD();
	 slt->tableInsert(cd);
   }
   ListDoublyLinkedIterator<CD>*table_iter = slt->iterator();
   while(table_iter->hasNext())
   {
		CD* cd = table_iter->next();
		cd->displayCD();
   }
   delete table_iter;
  /*delete iter;
  iter = cds->iterator();
  while(iter->hasNext())
  {
	CD* cd = iter->next();
    CD* show = slt->tableRetrieve(cd->getKey());
	last_cd = show;
	show->displayCD();
  }*/
  /*slt->tableRemove(last_cd->getKey()); // remove it 
  last_cd = slt->tableRetrieve(last_cd->getKey());// make sure it is gone
  last_cd->displayCD(); if it is gone this should be null and should crash the program
  */
   



   deleteCDs(cds);
   delete iter;
   delete cds;
   delete slt;
   return 0;
}
