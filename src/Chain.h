#ifndef CHAIN_H
#define CHAIN_H

#include "Block.h"

template<class t>
class Chain
{
private:
	int m_Blocks;
	
public:
	Block<t>* firstBlock;
	Block<t>* lastBlock;

	Chain(Block<t>* block)
	{
		firstBlock = block;
		lastBlock = block;
	}

	void AddBlock(Block<t>* block)
	{
		lastBlock->nextBlock = block;
		lastBlock->nextHash = block->getBlockHash();

		block->previosBlock = lastBlock;
		block->previosHash = lastBlock->getBlockHash();

		lastBlock = block;

	}
	
};

#endif // !CHAIN_H
