
#include "event.hpp"

GLAY_NS_BEGIN(Design)

/*
** Copy constructor.
*/
template<typename T>
Event<T>::Event (const Event<T>& other) :
	callbacks (other.callbacks)
{
}

/*
** Default constructor.
*/
template<typename T>
Event<T>::Event ()
{
}

/*
** Copy operator.
*/
template<typename T>
Event<T>&	Event<T>::operator = (const Event<T>& other)
{
	this->callbacks = other.callbacks;

	return *this;
}

/*
** Attach new callback to this event.
** callback:	new callback
*/
template<typename T>
void	Event<T>::bind (Callback callback)
{
	this->callbacks.push_back (callback);
}

/*
** Clear event's callbacks list.
*/
template<typename T>
void	Event<T>::clear ()
{
	this->callbacks.clear ();
}

/*
** Fire event callbacks.
** value:	callbacks argument
*/
template<typename T>
void	Event<T>::fire (T value) const
{
	for (auto i = this->callbacks.begin (); i != this->callbacks.end (); ++i)
		(*i) (value);
}

GLAY_NS_END()
