#ifndef DATA_H
#define DATA_H

#include <functional>

template <class t>
struct Data
{
private:
	t m_value;
public:
	void setValue(t value)
	{
		m_value = value;
	}

	const t getValue()
	{
		return m_value;
	}

	int getHashValue()
	{
		return std::hash<t>() (m_value);
	}
};

#endif // !DATA_H
