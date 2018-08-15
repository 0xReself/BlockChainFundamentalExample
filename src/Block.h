#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <vector>

#include "Data.h"

template<class t>
struct Block
{
private:
	int m_blockHash;
	std::vector<Data<t>*> m_changeOnData;
public:
	
	void addChangedDataToBlock(Data<t>* data)
	{
		m_changeOnData.push_back(data);
		for (int i = 0; i < m_changeOnData.size(); ++i)
		{
			m_blockHash += m_changeOnData[i]->getHashValue();
		}
	}

	int* getBlockHash()
	{
		return &m_blockHash;
	}

	Block<t>* nextBlock = nullptr;
	Block<t>* previosBlock = nullptr;
	int* nextHash = nullptr;
	int* previosHash = nullptr;
};

#endif // !BLOCK_H
