//Find
		void ShowItemTextTail(DWORD VirtualID);
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		void RegisterItemToolTipInfo(const DWORD& id, const std::tuple<const std::vector<long>, const std::vector<TPlayerItemAttribute>>& tooltiptuple);
		bool GetSocketsAndAttr(const DWORD& id, std::tuple<std::vector<long>, std::vector<TPlayerItemAttribute>>& ItemTuple);
#endif

//Find
		TChatTailMap				m_ChatTailMap;
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		std::map<DWORD, std::tuple<std::vector<long>, std::vector<TPlayerItemAttribute>>> ItemTooltipMap;
#endif
