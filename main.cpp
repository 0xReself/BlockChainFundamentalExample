#include <iostream>

#include "src/Chain.h"

int main()
{
	Data<int>* _data = new Data<int>;
	_data->setValue(2);

	Data<int>* _data2 = new Data<int>;
	_data2->setValue(3);

	Data<int>* _data3 = new Data<int>;
	_data2->setValue(6);

	Block<int>* block = new Block<int>();
	block->addChangedDataToBlock(_data);
	block->addChangedDataToBlock(_data2);

	Block<int>* block2 = new Block<int>();
	block2->addChangedDataToBlock(_data);
	block2->addChangedDataToBlock(_data2);
	block2->addChangedDataToBlock(_data3);

	Chain<int>* chain = new Chain<int>(block);
	chain->AddBlock(block2);

	std::cout << *chain->firstBlock->getBlockHash() << std::endl;
	std::cout << *chain->lastBlock->getBlockHash() << std::endl;

	system("Pause");
	return 0;
}