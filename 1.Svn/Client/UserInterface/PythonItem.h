//Find
		void	CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, float x, float y, float z, bool bDrop=true);
		
///Change
#if defined(TOOLTIP_GROUND_ITEM)
		void	CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, const std::tuple<const std::vector<long>, const std::vector<TPlayerItemAttribute>>& tooltiptuple, float x, float y, float z, bool bDrop=true);
#else
		void	CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, float x, float y, float z, bool bDrop=true);
#endif