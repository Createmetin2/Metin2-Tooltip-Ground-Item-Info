//Find
		void	CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, float x, float y, float z, bool bDrop=true);
		
///Change
		void	CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber,
#if defined(TOOLTIP_GROUND_ITEM)
			const long* socket, const TPlayerItemAttribute* attr,
#endif
			float x, float y, float z, bool bDrop = true);
