
#ifndef __GLAY_DESIGN_EVENT_HPP
#define __GLAY_DESIGN_EVENT_HPP

#include "../config.hpp"

#include <functional>
#include <vector>

GLAY_NS_BEGIN(Design)

template<typename T>
class Event
{
	public:
		typedef std::function<void (T)> Callback;

		Event (Event<T> const&);
		Event ();

		Event<T>& operator = (Event<T> const&);

		void bind (Callback);
		void clear ();
		void fire (T) const;

	private:
		typedef std::vector<Callback> Callbacks;

		Callbacks callbacks;
};

GLAY_NS_END()

#include "event.hxx"

#endif
