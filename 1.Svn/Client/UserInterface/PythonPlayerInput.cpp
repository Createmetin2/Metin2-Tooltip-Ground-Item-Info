//Find
void CPythonPlayer::__OnPressItem(CInstanceBase& rkInstMain, DWORD dwPickedItemID)

///Change
#ifdef TOOLTIP_GROUND_ITEM
void CPythonPlayer::__OnPressItem(CInstanceBase& rkInstMain, DWORD dwPickedItemID, bool rclick)
#else
void CPythonPlayer::__OnPressItem(CInstanceBase& rkInstMain, DWORD dwPickedItemID)
#endif

//Find
	SendClickItemPacket(dwPickedItemID);
	
///Change
#ifdef TOOLTIP_GROUND_ITEM
	SendClickItemPacket(dwPickedItemID, rclick);
#else
	SendClickItemPacket(dwPickedItemID);
#endif