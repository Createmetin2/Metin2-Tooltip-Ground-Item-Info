//Find
		void ShowItemTextTail(DWORD VirtualID);
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		void RegisterItemToolTipInfo(const DWORD& id, const std::pair<std::vector<long>, std::vector<TPlayerItemAttribute>>& TooltipData);
		bool GetSocketsAndAttr(const DWORD& id, std::pair<std::vector<long>, std::vector<TPlayerItemAttribute>>& TooltipData);
#endif

//Find
		TChatTailMap				m_ChatTailMap;
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		std::map<DWORD, std::pair<std::vector<long>, std::vector<TPlayerItemAttribute>>> ItemTooltipMap;
#endif
