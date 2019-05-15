#pragma once

#include <vector>

template <typename T>
class RoundRobin {
public:
	RoundRobin(size_t num = 0);

	virtual ~RoundRobin();

	//prevent assignment / assignment operator
	RoundRobin(const RoundRobin& src) = delete;
	RoundRobin& operator=(const RoundRobin& src) = delete;

	//adds element at the back
	void Add(const T& element);

	//remove first equal encounetered elemenet
	void Remove(const T& element);

	T& GetNext();

private:
	std::vector<T> m_Elements;
	typename std::vector<T>::iterator m_CurrentElement;
};

using namespace std;

template <typename T>
RoundRobin<T>::RoundRobin(size_t num) {
	m_Elements.reserve(num);
	m_CurrentElement = end(m_Elements);
}

template <typename T>
RoundRobin<T>::~RoundRobin() {}

template <typename T>
void RoundRobin<T>::Add(const T& element) {
	//save the current spot
	int pos = (m_CurrentElement == end(m_Elements) ? -1 : m_CurrentElement - begin(m_Elements));

	m_Elements.push_back(element);

	//re-set the pointer
	m_CurrentElement = ((pos == -1) ? end(m_Elements) : begin(m_Elements) + pos);
}

template <typename T>
void RoundRobin<T>::Remove(const T& element) {
	for (auto it = begin(m_Elements); it != end(m_Elements); ++it) {
		if (*it == element) {
			int newPos;

			if (m_CurrentElement <= it) {
				newPos = m_CurrentElement - begin(m_Elements);
			} else {
				newPos = m_CurrentElement - begin(m_Elements) - 1;
			}

			m_Elements.erase(it);
			m_CurrentElement = begin(m_Elements) + newPos;
			return;
		}
	}
}

template <typename T>
T& RoundRobin<T>::GetNext() {
	if (m_Elements.empty()) {
		throw out_of_range("List is empty.");
	}

	//first call
	if (m_CurrentElement == end(m_Elements)) {
		m_CurrentElement = begin(m_Elements);
	} else {
		++m_CurrentElement;

		if (m_CurrentElement == end(m_Elements)) m_CurrentElement = begin(m_Elements);
	}

	return *m_CurrentElement;
}