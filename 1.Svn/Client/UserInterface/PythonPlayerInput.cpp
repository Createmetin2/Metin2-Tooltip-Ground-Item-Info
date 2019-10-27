//Find
void CPythonPlayer::__OnPressItem(CInstanceBase& rkInstMain, DWORD dwPickedItemID)

///Change
void CPythonPlayer::__OnPressItem(CInstanceBase& rkInstMain, DWORD dwPickedItemID
#if defined(TOOLTIP_GROUND_ITEM)
,bool rclick
#endif
)

//Find
	__ReserveClickItem(dwPickedItemID);
	
///Change
	__ReserveClickItem(dwPickedItemID
#if defined(TOOLTIP_GROUND_ITEM)
		,rclick
#endif
	);

//Find
	SendClickItemPacket(dwPickedItemID);
	
///Change
	SendClickItemPacket(dwPickedItemID
#ifdef TOOLTIP_GROUND_ITEM	
	,rclick
#endif
	);

//Find
void CPythonPlayer::__ReserveClickItem(DWORD dwItemID)

///Change
void CPythonPlayer::__ReserveClickItem(DWORD dwItemID
#ifdef TOOLTIP_GROUND_ITEM
,bool rclick
#endif
)

//Find
	m_eReservedMode=MODE_CLICK_ITEM;
	
///Change
#if defined(TOOLTIP_GROUND_ITEM)
	m_eReservedMode = rclick ? MODE_CLICK_ITEM_RIGHT : MODE_CLICK_ITEM;
#else
	m_eReservedMode=MODE_CLICK_ITEM;
#endif