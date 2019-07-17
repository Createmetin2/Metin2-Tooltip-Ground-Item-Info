//Find
		void	CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, float x, float y, float z, bool bDrop=true);
		
///Change
#ifdef TOOLTIP_GROUND_ITEM
		void	CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, const std::vector<long>& sockets, const std::vector<BYTE>& attrtype, const std::vector<short>& attrvals, float x, float y, float z, bool bDrop=true);
#else
		void	CreateItem(DWORD dwVirtualID, DWORD dwVirtualNumber, float x, float y, float z, bool bDrop=true);
#endif