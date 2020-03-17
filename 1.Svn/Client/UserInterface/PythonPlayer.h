//Find
			MODE_USE_SKILL,
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
			MODE_CLICK_ITEM_RIGHT,
#endif
		
//Find
		void	__ReserveClickItem(DWORD dwItemID);
		
///Change
		void	__ReserveClickItem(DWORD dwItemID
#if defined(TOOLTIP_GROUND_ITEM)
		,bool rclick = false
#endif
		);

//Find
		void	SendClickItemPacket(DWORD dwIID);
	
///Change
#ifdef TOOLTIP_GROUND_ITEM
		void	ClickRight(const int& eMBT);
		void	SendClickItemPacket(DWORD dwIID, bool rclick = false);
#else
		void	SendClickItemPacket(DWORD dwIID);
#endif
	
//Find
		void	__OnPressItem(CInstanceBase& rkInstMain, DWORD dwPickedItemID);
	
///Change
		void	__OnPressItem(CInstanceBase& rkInstMain, DWORD dwPickedItemID
#if defined(TOOLTIP_GROUND_ITEM)
		,bool rclick = false
#endif
		);