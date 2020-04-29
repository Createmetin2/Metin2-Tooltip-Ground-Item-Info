//Find in void CPythonPlayer::SendClickItemPacket(DWORD dwIID)
		const char * c_szOwnerName;
		if (!CPythonItem::Instance().GetOwnership(dwIID, &c_szOwnerName))
			return;
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		if (rclick) {
			try {
				const auto& tooltip = CPythonTextTail::instance().GetTooltipMap().at(dwIID);
				CItemData* pItemData;
				if (CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData))
					PyCallClassMemberFunc(m_ppyGameWindow, "ShowItemFromClient", Py_BuildValue("ii[OO]is", TRUE, pItemData->GetTable()->dwVnum,
						tooltip->operator[](tooltip->T_SOCKET), tooltip->operator[](tooltip->T_ATTR), dwIID, tooltip->GetOwner().c_str()));
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
