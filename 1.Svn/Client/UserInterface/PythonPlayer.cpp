//Find in void CPythonPlayer::SendClickItemPacket(DWORD dwIID)
	if (dwCurTime >= s_dwNextTCPTime)
	{
		s_dwNextTCPTime=dwCurTime + 500;
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		if (rclick) {
			std::pair<std::vector<long>, std::vector<TPlayerItemAttribute>> TooltipItemData;
			CItemData* pItemData;
			if (!CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData) || !CPythonTextTail::instance().GetSocketsAndAttr(dwIID, TooltipItemData))
				return;

			enum { T_SOCKET, T_TYPE, T_VALUE };
			static const std::vector<PyObject*> _TDATA {
				PyTuple_New(static_cast<Py_ssize_t>(ITEM_SOCKET_SLOT_MAX_NUM)), // socket
				PyTuple_New(static_cast<Py_ssize_t>(ITEM_ATTRIBUTE_SLOT_MAX_NUM)), // attr type
				PyTuple_New(static_cast<Py_ssize_t>(ITEM_ATTRIBUTE_SLOT_MAX_NUM)) // // attr val
			};

			const auto& _sockets(TooltipItemData.first);
			const auto& _attr(TooltipItemData.second);

			for (size_t i = 0; i < _sockets.size(); i++)
				PyTuple_SetItem(_TDATA[T_SOCKET], i, PyInt_FromLong(_sockets.at(i)));

			for (size_t i = 0; i < _attr.size(); i++) {
				PyTuple_SetItem(_TDATA[T_TYPE], i, PyInt_FromLong(static_cast<long>(_attr.at(i).bType)));
				PyTuple_SetItem(_TDATA[T_VALUE], i, PyInt_FromLong(static_cast<long>(_attr.at(i).sValue)));
			}

			PyCallClassMemberFunc(m_ppyGameWindow, "ShowItemFromClient", Py_BuildValue("iiOOOi", TRUE, pItemData->GetTable()->dwVnum, _TDATA[T_SOCKET], _TDATA[T_TYPE], _TDATA[T_VALUE], dwIID));
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
