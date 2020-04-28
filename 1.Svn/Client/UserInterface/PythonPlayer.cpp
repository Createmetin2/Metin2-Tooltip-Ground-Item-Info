//Find in void CPythonPlayer::SendClickItemPacket(DWORD dwIID)
	if (dwCurTime >= s_dwNextTCPTime)
	{
		s_dwNextTCPTime=dwCurTime + 500;
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
	if (rclick) {	
		try {
			const auto& tooltip = CPythonTextTail::instance().GetTooltipMap().at(dwIID);
			CItemData* pItemData;
			if (CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData))
				PyCallClassMemberFunc(m_ppyGameWindow, "ShowItemFromClient", Py_BuildValue("ii[OO]i", TRUE, pItemData->GetTable()->dwVnum,
			tooltip->operator[](tooltip->T_SOCKET), tooltip->operator[](tooltip->T_ATTR), dwIID));
		}
		catch (const std::out_of_range & err) { Tracenf("CPythonPlayer::SendClickItemPacket:Tooltip Info out_of_range (dwIID=%d) (what=> %s)", dwIID, err.what()); }
		return; // rclick
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
