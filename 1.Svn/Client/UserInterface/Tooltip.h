#pragma once
#include <array>

#if defined(TOOLTIP_GROUND_ITEM)
class TooltipData
{
public:
	TooltipData(const long* socket, const TPlayerItemAttribute* attr) {
		Tuple.at(T_SOCKET) = PyTuple_New(ITEM_SOCKET_SLOT_MAX_NUM);
		for (size_t i = T_TYPE; i <= T_VALUE; i++)
			Tuple.at(i) = PyTuple_New(ITEM_ATTRIBUTE_SLOT_MAX_NUM);

		for (size_t i = 0; i < ITEM_SOCKET_SLOT_MAX_NUM; i++)
			PyTuple_SetItem(Tuple.at(T_SOCKET), i, PyInt_FromLong(socket[i]));

		for (size_t i = 0; i < ITEM_ATTRIBUTE_SLOT_MAX_NUM; i++) {
			PyTuple_SetItem(Tuple.at(T_TYPE), i, PyInt_FromLong(attr[i].bType));
			PyTuple_SetItem(Tuple.at(T_VALUE), i, PyInt_FromLong(attr[i].sValue));
		}
	}
	~TooltipData() {
		for (const auto& v : Tuple)
			Py_DECREF(v);
	}

	enum TooltipEnum : size_t { T_SOCKET, T_TYPE, T_VALUE, T_MAX };
	auto operator[] (const size_t& idx) const { return Tuple.at(idx); };

private:
	std::array<PyObject*, T_MAX> Tuple;
};
#endif
