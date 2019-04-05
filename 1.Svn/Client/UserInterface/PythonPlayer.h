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