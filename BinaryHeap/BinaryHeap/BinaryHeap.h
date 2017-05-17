#pragma once

#include <vector>

template <typename T>
class CBinaryHeap
{
public:
	CBinaryHeap(int _capacity = 100);
	bool IsEmpty() const;
	const T& GetMin() const;
	void Insert(const T& _item);
	void DeleteMin();
	void DeleteMin(T& _rMinItem);
	int GetSize() const;

private:
	std::vector<T> m_vecHeap; // The heap array

	void WalkUp();
	void WalkDown();
	void Swap(int _idx1, int _idx2);
	// Returns 0 when both indices are out of bounds
	int GetMinChildIdx(int _iLeftIdx, int _iRightIdx) const;
};

template<typename T>
inline CBinaryHeap<T>::CBinaryHeap(int _iCapacity)
{
	m_vecHeap.reserve(_iCapacity);
	m_vecHeap.emplace_back();
}

template<typename T>
inline bool CBinaryHeap<T>::IsEmpty() const
{
	return (GetSize() == 0);
}

template<typename T>
inline const T & CBinaryHeap<T>::GetMin() const
{
	return m_vecHeap.at(1);
}

template<typename T>
inline void CBinaryHeap<T>::Insert(const T & _item)
{
	m_vecHeap.push_back(_item);

	WalkUp();
}

template<typename T>
inline void CBinaryHeap<T>::DeleteMin()
{
	T dummy;
	DeleteMin(dummy);
}

template<typename T>
inline void CBinaryHeap<T>::DeleteMin(T & _rMinItem)
{
	if (!IsEmpty())
	{
		_rMinItem = m_vecHeap[1];
		m_vecHeap[1] = m_vecHeap[GetSize()];
		m_vecHeap.pop_back();
	}

	WalkDown();
}

template<typename T>
inline int CBinaryHeap<T>::GetSize() const
{
	return m_vecHeap.size() - 1;
}

template<typename T>
inline void CBinaryHeap<T>::WalkUp()
{
	int iCurIdx = GetSize();
	int iParentIdx = iCurIdx / 2;

	while (iCurIdx > 1 && m_vecHeap[iCurIdx] < m_vecHeap[iParentIdx])
	{
		Swap(iCurIdx, iParentIdx);

		iCurIdx = iParentIdx;
		iParentIdx = iCurIdx / 2;
	}
}

template<typename T>
inline void CBinaryHeap<T>::WalkDown()
{
	int iCurIdx = 1;
	int iLeftChildIdx = iCurIdx * 2;
	int iRightChildIdx = iCurIdx * 2 + 1;

	// Until we reach the end of the tree
	while (iCurIdx <= GetSize())
	{
		// Get min child index
		int iMinChildIdx = GetMinChildIdx(iLeftChildIdx, iRightChildIdx);

		// Swap if the min child is less than the current node
		if (iMinChildIdx && m_vecHeap[iMinChildIdx] < m_vecHeap[iCurIdx])
		{
			Swap(iCurIdx, iMinChildIdx);

			// Continue traversing down the tree
			iCurIdx = iMinChildIdx;
			iLeftChildIdx = iCurIdx * 2;
			iRightChildIdx = iCurIdx * 2 + 1;
		}
		// Return if the node has reached its correct position
		else
		{
			return;
		}
	}
}

template<typename T>
inline void CBinaryHeap<T>::Swap(int _idx1, int _idx2)
{
	T tmp = m_vecHeap[_idx1];
	m_vecHeap[_idx1] = m_vecHeap[_idx2];
	m_vecHeap[_idx2] = tmp;
}

template<typename T>
inline int CBinaryHeap<T>::GetMinChildIdx(int _iLeftIdx, int _iRightIdx) const
{
	// Both children exist
	if (_iRightIdx <= GetSize())
	{
		return (m_vecHeap[_iLeftIdx] < m_vecHeap[_iRightIdx]) ?
			_iLeftIdx : _iRightIdx;
	}
	// Only the left child exists
	else if (_iLeftIdx <= GetSize())
	{
		return _iLeftIdx;
	}
	// The current node is a leaf node
	else
	{
		return 0;
	}
}
