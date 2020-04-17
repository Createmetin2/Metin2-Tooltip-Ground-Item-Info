//Find in void CPythonPlayer::SendClickItemPacket(DWORD dwIID)
	if (dwCurTime >= s_dwNextTCPTime)
	{
		s_dwNextTCPTime=dwCurTime + 500;
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
	if (rclick) {
		CItemData* pItemData;
		if (!CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData))
			return;

		const auto tooltip = CPythonTextTail::instance().GetTooltipData(dwIID);
		if (!tooltip)
			return;

		PyCallClassMemberFunc(m_ppyGameWindow, "ShowItemFromClient", Py_BuildValue("iiO[OO]i", TRUE, pItemData->GetTable()->dwVnum, 
			tooltip->operator[](tooltip->T_SOCKET), tooltip->operator[](tooltip->T_TYPE), tooltip->operator[](tooltip->T_VALUE), dwIID));
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
