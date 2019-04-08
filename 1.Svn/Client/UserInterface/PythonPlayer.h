//Find
			MODE_USE_SKILL,
		
///Add
		#ifdef TOOLTIP_GROUND_ITEM
			MODE_CLICK_ITEM_RIGHT,
		#endif
		
//Find
		void	__ReserveClickItem(DWORD dwItemID);
		
///Change
#ifdef TOOLTIP_GROUND_ITEM
		void	__ReserveClickItem(DWORD dwItemID, bool rclick = false);
#else
		void	__ReserveClickItem(DWORD dwItemID);
#endif

//Find
		void	SendClickItemPacket(DWORD dwIID);
	
///Change
	#ifdef TOOLTIP_GROUND_ITEM
		void	ClickRight(int eMBT);
		void	SendClickItemPacket(DWORD dwIID, bool rclick = false);
	#else
		void	SendClickItemPacket(DWORD dwIID);
	#endif
	
//Find
		void	__OnPressItem(CInstanceBase& rkInstMain, DWORD dwPickedItemID);
	
///Change
	#ifdef TOOLTIP_GROUND_ITEM
		void	__OnPressItem(CInstanceBase& rkInstMain, DWORD dwPickedItemID, bool rclick = false);
	#else
		void	__OnPressItem(CInstanceBase& rkInstMain, DWORD dwPickedItemID);
	#endif