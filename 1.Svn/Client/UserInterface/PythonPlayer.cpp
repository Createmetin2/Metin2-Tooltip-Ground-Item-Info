//Find in void CPythonPlayer::SendClickItemPacket(DWORD dwIID)
	if (dwCurTime >= s_dwNextTCPTime)
	{
		s_dwNextTCPTime=dwCurTime + 500;
		
///Add
	#ifdef TOOLTIP_GROUND_ITEM
		if (rclick) {
			CItemData * pItemData;
			if (!CItemManager::Instance().GetItemDataPointer(CPythonItem::Instance().GetVirtualNumberOfGroundItem(dwIID), &pItemData))
			{
				Tracenf("CPythonPlayer::SendClickItemPacket(dwIID=%d) : Non-exist item.", dwIID);
				return;
			}
			PyCallClassMemberFunc(m_ppyGameWindow, "ShowItemFromClient", Py_BuildValue("ii[lll][[ii][ii][ii][ii][ii][ii][ii]]", TRUE, pItemData->GetTable()->dwVnum, 
				pItemData->GetSockets(0), pItemData->GetSockets(1), pItemData->GetSockets(2), 
				pItemData->GetAttrType(0), pItemData->GetAttrVal(0),
				pItemData->GetAttrType(1), pItemData->GetAttrVal(1),
				pItemData->GetAttrType(2), pItemData->GetAttrVal(2),
				pItemData->GetAttrType(3), pItemData->GetAttrVal(3),
				pItemData->GetAttrType(4), pItemData->GetAttrVal(4),
				pItemData->GetAttrType(5), pItemData->GetAttrVal(5),
				pItemData->GetAttrType(6), pItemData->GetAttrVal(6)
			));
			return;
		}
	#endif

//Find
void CPythonPlayer::SendClickItemPacket(DWORD dwIID)

///Change
#ifdef TOOLTIP_GROUND_ITEM
void CPythonPlayer::SendClickItemPacket(DWORD dwIID, bool rclick)
#else
void CPythonPlayer::SendClickItemPacket(DWORD dwIID)	
#endif