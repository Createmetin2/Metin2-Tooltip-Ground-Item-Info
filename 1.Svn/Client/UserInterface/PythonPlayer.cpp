//Find in void CPythonPlayer::SendClickItemPacket(DWORD dwIID)
	if (dwCurTime >= s_dwNextTCPTime)
	{
		s_dwNextTCPTime=dwCurTime + 500;
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		if (rclick) {	
			std::tuple<std::vector<long>, std::vector<TPlayerItemAttribute>> ItemTuple;
			CItemData* pItemData;
			if (!CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData) || !CPythonTextTail::instance().GetSocketsAndAttr(dwIID, ItemTuple))
				return;	

			const auto sockets = PyTuple_New(static_cast<Py_ssize_t>(ITEM_SOCKET_SLOT_MAX_NUM));
			const auto& _sockets = std::get<0>(ItemTuple);
			for (size_t i = 0; i < _sockets.size(); i++)
				PyTuple_SetItem(sockets, i, PyInt_FromLong(_sockets.at(i)));

			std::array< PyObject*, 2> attr;
			std::generate(std::begin(attr), std::end(attr), []() { return PyTuple_New(static_cast<Py_ssize_t>(ITEM_ATTRIBUTE_SLOT_MAX_NUM)); });

			const auto& _attr = std::get<1>(ItemTuple);
			for (size_t i = 0; i < _attr.size(); i++) {
				PyTuple_SetItem(attr.at(0), i, PyInt_FromLong(_attr.at(i).bType));
				PyTuple_SetItem(attr.at(1), i, PyInt_FromLong(_attr.at(i).sValue));
			}

			PyCallClassMemberFunc(m_ppyGameWindow, "ShowItemFromClient", Py_BuildValue("iiOOOi", TRUE, pItemData->GetTable()->dwVnum, sockets, attr[0], attr[1], dwIID));
			
			for (auto&v : attr)
				Py_DECREF(v);
			Py_DECREF(sockets);

			return;
		}
#endif

//Find
void CPythonPlayer::SendClickItemPacket(DWORD dwIID)

///Change
#if defined(TOOLTIP_GROUND_ITEM)
#include "PythonTextTail.h"
void CPythonPlayer::SendClickItemPacket(DWORD dwIID, bool rclick)
#else
void CPythonPlayer::SendClickItemPacket(DWORD dwIID)	
#endif
