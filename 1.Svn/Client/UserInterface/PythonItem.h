//Find
		void	CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, float x, float y, float z, bool bDrop=true);
		
///Change
		void	CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber,
#if defined(TOOLTIP_GROUND_ITEM)
		const std::tuple<const std::vector<long>, const std::vector<TPlayerItemAttribute>>& tooltiptuple,
#endif
		float x, float y, float z, bool bDrop=true);
