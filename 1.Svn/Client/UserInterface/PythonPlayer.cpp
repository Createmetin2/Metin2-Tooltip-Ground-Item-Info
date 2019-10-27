//Find in void CPythonPlayer::SendClickItemPacket(DWORD dwIID)
	if (dwCurTime >= s_dwNextTCPTime)
	{
		s_dwNextTCPTime=dwCurTime + 500;
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		if (rclick) {
			CItemData* pItemData;
			std::vector<long> allsockets; std::vector<TPlayerItemAttribute> allattr;
			if (!CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData) || !CPythonTextTail::instance().GetSocketsAndAttr(dwIID, allsockets, allattr))
				return;
			PyObject* sockets = PyTuple_New(ITEM_SOCKET_SLOT_MAX_NUM);
			std::array< PyObject*, 2> attr;
			for (size_t i = 0; i < attr.size(); i++)
				attr.at(i) = PyTuple_New(ITEM_ATTRIBUTE_SLOT_MAX_NUM);
			for (size_t i = 0; i< allsockets.size(); i++)
				PyTuple_SetItem(sockets, i, PyInt_FromLong(allsockets.at(i)));
			for (size_t i = 0; i < allattr.size(); i++) {
				PyTuple_SetItem(attr.at(0), i, PyInt_FromLong(allattr.at(i).bType));
				PyTuple_SetItem(attr.at(1), i, PyInt_FromLong(allattr.at(i).sValue));
			}
			PyCallClassMemberFunc(m_ppyGameWindow, "ShowItemFromClient", Py_BuildValue("iiOOOi", TRUE, pItemData->GetTable()->dwVnum, sockets, attr[0], attr[1], dwIID));
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
