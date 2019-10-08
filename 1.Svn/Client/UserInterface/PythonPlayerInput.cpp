//Find
void CPythonPlayer::__OnPressItem(CInstanceBase& rkInstMain, DWORD dwPickedItemID)

///Change
#ifdef TOOLTIP_GROUND_ITEM
void CPythonPlayer::__OnPressItem(CInstanceBase& rkInstMain, DWORD dwPickedItemID, bool rclick)
#else
void CPythonPlayer::__OnPressItem(CInstanceBase& rkInstMain, DWORD dwPickedItemID)
#endif

//Find
	__ReserveClickItem(dwPickedItemID);
	
///Change
	__ReserveClickItem(dwPickedItemID
#ifdef TOOLTIP_GROUND_ITEM
		,rclick
#endif
	);

//Find
	SendClickItemPacket(dwPickedItemID);
	
///Change
#ifdef TOOLTIP_GROUND_ITEM
	SendClickItemPacket(dwPickedItemID, rclick);
#else
	SendClickItemPacket(dwPickedItemID);
#endif

//Find
void CPythonPlayer::__ReserveClickItem(DWORD dwItemID)

///Change
#ifdef TOOLTIP_GROUND_ITEM
void CPythonPlayer::__ReserveClickItem(DWORD dwItemID, bool rclick)
#else
void CPythonPlayer::__ReserveClickItem(DWORD dwItemID)
#endif

//Find
	m_eReservedMode=MODE_CLICK_ITEM;
	
///Change
#ifdef TOOLTIP_GROUND_ITEM
	m_eReservedMode = rclick ? MODE_CLICK_ITEM_RIGHT : MODE_CLICK_ITEM;
#else
	m_eReservedMode=MODE_CLICK_ITEM;
#endif