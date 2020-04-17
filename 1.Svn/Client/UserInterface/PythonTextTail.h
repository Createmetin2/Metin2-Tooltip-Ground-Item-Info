//Find
		void ShowItemTextTail(DWORD VirtualID);
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		std::shared_ptr<TooltipData> GetTooltipData(const DWORD& id) { return ItemTooltipMap.find(id) == ItemTooltipMap.end() ? nullptr : ItemTooltipMap.at(id); };
#endif

//Find
		void RegisterItemTextTail(DWORD VirtualID, const char * c_szText, CGraphicObjectInstance * pOwner)
		
///Change
		void RegisterItemTextTail(DWORD VirtualID, const char * c_szText, CGraphicObjectInstance * pOwner
#if defined(TOOLTIP_GROUND_ITEM)
		, const long* socket, const TPlayerItemAttribute* attr
#endif
		);

//Find
		TChatTailMap				m_ChatTailMap;
		
///Add
#if defined(TOOLTIP_GROUND_ITEM)
		std::map<DWORD, std::shared_ptr<TooltipData>> ItemTooltipMap;
#endif
